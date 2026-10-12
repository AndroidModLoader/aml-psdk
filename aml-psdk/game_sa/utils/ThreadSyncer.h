#ifndef __AML_PSDK_SATHREADSYNCER_H
#define __AML_PSDK_SATHREADSYNCER_H

#include <aml-psdk/game_sa/Events.h>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <future>
#include <memory>
#include <type_traits>
#include <utility>

struct ThreadSyncer
{
    ThreadSyncer()
    {
        Events::gameProcessEvent.after += ProcessMainThreadTasks;
    }

    static inline void ExecInThread(std::function<void()> fn)
    {
        std::thread t(std::move(fn));
        t.detach();
    }

    static inline void PushToMain(std::function<void()> fn)
    {
        std::lock_guard<std::mutex> lock(m_queueMainMutex);
        m_queueMainTasks.push(std::move(fn));
    }

    template<typename Fn>
    static inline auto SubmitToMain(Fn&& fn) -> std::future<std::invoke_result_t<std::decay_t<Fn>&>>
    {
        typedef std::invoke_result_t<std::decay_t<Fn>&> Result;
        auto task = std::make_shared<std::packaged_task<Result()>>(std::forward<Fn>(fn));
        auto result = task->get_future();
        PushToMain([task]() { (*task)(); });
        return result;
    }

    static inline void ProcessMainThreadTasks()
    {
        std::queue<std::function<void()>> local_tasks;
        {
            std::lock_guard<std::mutex> lock(m_queueMainMutex);
            std::swap(m_queueMainTasks, local_tasks);
        }

        while(!local_tasks.empty())
        {
            auto task = std::move(local_tasks.front());
            local_tasks.pop();
            task();
        }
    }

    static inline std::mutex m_queueMainMutex;
    static inline std::queue<std::function<void()>> m_queueMainTasks;
};
inline ThreadSyncer g_ThreadSyncerStub;

#endif // __AML_PSDK_SATHREADSYNCER_H

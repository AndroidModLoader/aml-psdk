#ifndef __AML_PSDK_SAAIEVENT_H
#define __AML_PSDK_SAAIEVENT_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;

struct CEvent;

DECL_CLASS_VTABLE(CEventGroup)
    CPed         *m_pPed;
    int           m_dwCount;
    CEvent       *m_apEvents[16];
DECL_CLASS_END()

#endif // __AML_PSDK_SAAIEVENT_H

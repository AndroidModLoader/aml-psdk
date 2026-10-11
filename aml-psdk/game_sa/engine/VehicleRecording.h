#ifndef __AML_PSDK_SAVEHICLERECORDING_H
#define __AML_PSDK_SAVEHICLERECORDING_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CVehicle;
struct CMatrix;
struct RwStream;

struct CVehicleStateEachFrame
{
    u32 m_nTime;
    i16 m_sVelocity[3];
    i8 m_bRight[3];
    i8 m_bTop[3];
    i8 m_bSteeringAngle;
    i8 m_bGasPedalPower;
    i8 m_bBreakPedalPower;
    i8 m_bHandbrakeUsed;
    CVector m_vecPosn;
};
CHECKSIZE(CVehicleStateEachFrame, 0x20, 0x20);

struct CPath
{
    i32 m_nNumber;
    u8 *m_pData;
    i32 m_nSize;
    u8 m_nRefCount;
};
CHECKSIZE(CPath, 0x10, 0x18);

DECL_CLASS(CVehicleRecording)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitAtStartOfGame, _ZN17CVehicleRecording17InitAtStartOfGameEv, void);
    DECL_FASTCALL_SIMPLE(Init, _ZN17CVehicleRecording4InitEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN17CVehicleRecording8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(StartPlaybackRecordedCar, _ZN17CVehicleRecording24StartPlaybackRecordedCarEP8CVehiclejbb, void,
        CVehicle* pVehicle, u32 fileNumber, bool bUseCarAI, bool bLooped);
    DECL_FASTCALL_SIMPLE(FindIndexWithFileNameNumber, _ZN17CVehicleRecording27FindIndexWithFileNameNumberEi, i32, i32 fileNumber);
    DECL_FASTCALL_SIMPLE(RequestRecordingFile, _ZN17CVehicleRecording20RequestRecordingFileEi, void, i32 fileNumber);
    DECL_FASTCALL_SIMPLE(SetRecordingToPointClosestToCoors, _ZN17CVehicleRecording33SetRecordingToPointClosestToCoorsEi7CVector, void, i32 playbackId, CVector posn);
    DECL_FASTCALL_SIMPLE(StopPlaybackRecordedCar, _ZN17CVehicleRecording23StopPlaybackRecordedCarEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(StopPlaybackWithIndex, _ZN17CVehicleRecording21StopPlaybackWithIndexEi, void, i32 playbackId);
    DECL_FASTCALL_SIMPLE(IsPlaybackGoingOnForCar, _ZN17CVehicleRecording23IsPlaybackGoingOnForCarEP8CVehicle, bool, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(IsPlaybackPausedForCar, _ZN17CVehicleRecording22IsPlaybackPausedForCarEP8CVehicle, bool, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(SetPlaybackSpeed, _ZN17CVehicleRecording16SetPlaybackSpeedEP8CVehiclef, void, CVehicle* vehicle, float speed);
    DECL_FASTCALL_SIMPLE(PausePlaybackRecordedCar, _ZN17CVehicleRecording24PausePlaybackRecordedCarEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(UnpausePlaybackRecordedCar, _ZN17CVehicleRecording26UnpausePlaybackRecordedCarEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(ChangeCarPlaybackToUseAI, _ZN17CVehicleRecording24ChangeCarPlaybackToUseAIEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(SkipToEndAndStopPlaybackRecordedCar, _ZN17CVehicleRecording35SkipToEndAndStopPlaybackRecordedCarEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(RestoreInfoForCar, _ZN17CVehicleRecording17RestoreInfoForCarEP8CVehicleP22CVehicleStateEachFrameb, void,
        CVehicle* pVehicle, CVehicleStateEachFrame* pFrame, bool bPause);
    DECL_FASTCALL_SIMPLE(SaveOrRetrieveDataForThisFrame, _ZN17CVehicleRecording30SaveOrRetrieveDataForThisFrameEv, void);
    DECL_FASTCALL_SIMPLE(InterpolateInfoForCar, _ZN17CVehicleRecording21InterpolateInfoForCarEP8CVehicleP22CVehicleStateEachFramef, void,
        CVehicle* pVehicle, CVehicleStateEachFrame* pFrame, float interpValue);
    DECL_FASTCALL_SIMPLE(RestoreInfoForMatrix, _ZN17CVehicleRecording20RestoreInfoForMatrixER7CMatrixP22CVehicleStateEachFrame, void, CMatrix& matrix, CVehicleStateEachFrame* pFrame);
    DECL_FASTCALL_SIMPLE(SkipForwardInRecording, _ZN17CVehicleRecording22SkipForwardInRecordingEP8CVehiclef, void, CVehicle* vehicle, float distance);
    DECL_FASTCALL_SIMPLE(RenderLineSegment, _ZN17CVehicleRecording17RenderLineSegmentERi, void, i32& numVertices);
    DECL_FASTCALL_SIMPLE(Render, _ZN17CVehicleRecording6RenderEv, void);
    DECL_FASTCALL_SIMPLE(RegisterRecordingFile, _ZN17CVehicleRecording21RegisterRecordingFileEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(HasRecordingFileBeenLoaded, _ZN17CVehicleRecording26HasRecordingFileBeenLoadedEi, bool, i32 fileNumber);
    DECL_FASTCALL_SIMPLE(RemoveRecordingFile, _ZN17CVehicleRecording19RemoveRecordingFileEi, void, i32 fileNumber);
    DECL_FASTCALL_SIMPLE(Load, _ZN17CVehicleRecording4LoadEP8RwStreamii, void, RwStream* stream, i32 recordId, i32 totalSize);
    DECL_FASTCALL_SIMPLE(SmoothRecording, _ZN17CVehicleRecording15SmoothRecordingEi, void, i32 recordId);
    DECL_FASTCALL_SIMPLE(RemoveAllRecordingsThatArentUsed, _ZN17CVehicleRecording32RemoveAllRecordingsThatArentUsedEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CVehicle*, pVehicleForPlayback, BYBIT(0x677A80, 0x84D528));
    DECL_OBJECT_ARRAY_PLT(u8*, pPlaybackBuffer, BYBIT(0x678E30, 0x84FC88));
    DECL_OBJECT_ARRAY_PLT(i32, PlaybackIndex, BYBIT(0x678A00, 0x84F420));
    DECL_OBJECT_ARRAY_PLT(i32, PlaybackBufferSize, BYBIT(0x679B24, 0x851668));
    DECL_OBJECT_ARRAY_PLT(float, PlaybackRunningTime, BYBIT(0x678BCC, 0x84F7C0));
    DECL_OBJECT_ARRAY_PLT(float, PlaybackSpeed, BYBIT(0x67797C, 0x84D320));
    DECL_OBJECT_ARRAY_PLT(bool, bPlaybackGoingOn, BYBIT(0x678608, 0x84EC28));
    DECL_OBJECT_ARRAY_PLT(bool, bPlaybackLooped, BYBIT(0x6799A4, 0x851360));
    DECL_OBJECT_ARRAY_PLT(bool, bPlaybackPaused, BYBIT(0x6774D0, 0x84C9D8));
    DECL_OBJECT_ARRAY_PLT(bool, bUseCarAI, BYBIT(0x677C10, 0x84D840));
    DECL_OBJECT_ARRAY_SYM(u8, DisplayMode, _ZN17CVehicleRecording11DisplayModeE);
    DECL_OBJECT_ARRAY_PLT(i32, PlayBackStreamingIndex, BYBIT(0x677DC8, 0x84DBB0));
    DECL_OBJECT_ARRAY_PLT(CPath, StreamingArray, BYBIT(0x679B70, 0x851700));
    DECL_VALUE_PLT_I32(NumPlayBackFiles, BYBIT(0x67894C, 0x84F2B8));
DECL_CLASS_END()

#define pVehicleForPlayback pVehicleForPlayback()
#define pPlaybackBuffer pPlaybackBuffer()
#define PlaybackIndex PlaybackIndex()
#define PlaybackBufferSize PlaybackBufferSize()
#define PlaybackRunningTime PlaybackRunningTime()
#define PlaybackSpeed PlaybackSpeed()
#define bPlaybackGoingOn bPlaybackGoingOn()
#define bPlaybackLooped bPlaybackLooped()
#define bPlaybackPaused bPlaybackPaused()
#define bUseCarAI bUseCarAI()
#define DisplayMode DisplayMode()
#define PlayBackStreamingIndex PlayBackStreamingIndex()
#define StreamingArray StreamingArray()
#define NumPlayBackFiles NumPlayBackFiles()

#endif // __AML_PSDK_SAVEHICLERECORDING_H

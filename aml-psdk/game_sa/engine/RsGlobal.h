#ifndef __AML_PSDK_SARSGLOBAL_H
#define __AML_PSDK_SARSGLOBAL_H

#include <aml-psdk/game_sa/plugin.h>

enum RsInputDeviceType : i32
{
    rsKEYBOARD = 0,
    rsMOUSE = 1,
    rsPAD = 2,
};

enum RsEventStatus : i32
{
    rsEVENTERROR = 0,
    rsEVENTPROCESSED = 1,
    rsEVENTNOTPROCESSED = 2,
};

enum RsEvent : i32
{
    rsCAMERASIZE = 0,
    rsCOMMANDLINE = 1,
    rsFILELOAD = 2,
    rsINITDEBUG = 3,
    rsINPUTDEVICEATTACH = 4,
    rsLEFTBUTTONDOWN = 5,
    rsLEFTBUTTONUP = 6,
    rsMOUSEMOVE = 7,
    rsMOUSEWHEELMOVE = 8,
    rsPLUGINATTACH = 9,
    rsREGISTERIMAGELOADER = 10,
    rsRIGHTBUTTONDOWN = 11,
    rsRIGHTBUTTONUP = 12,
    rsMIDDLEBUTTONDOWN = 13,
    rsMIDDLEBUTTONUP = 14,
    rsMOUSEWHEELMOVEDUP = 15,
    rsMOUSEWHEELMOVEDDOWN = 16,
    rsFIRST_XBUTTONUP = 17,
    rsSECOND_XBUTTONUP = 18,
    rsFIRST_XBUTTONDOWN = 19,
    rsSECOND_XBUTTONDOWN = 20,
    rsRWINITIALIZE = 21,
    rsRWTERMINATE = 22,
    rsSELECTDEVICE = 23,
    rsINITIALIZE = 24,
    rsTERMINATE = 25,
    rsIDLE = 26,
    rsFRONTENDIDLE = 27,
    rsKEYDOWN = 28,
    rsKEYUP = 29,
    rsQUITAPP = 30,
    rsPADBUTTONDOWN = 31,
    rsPADBUTTONUP = 32,
    rsPADANALOGUELEFT = 33,
    rsPADANALOGUELEFTRESET = 34,
    rsPADANALOGUERIGHT = 35,
    rsPADANALOGUERIGHTRESET = 36,
    rsPREINITCOMMANDLINE = 37,
    rsACTIVATE = 38,
    rsSETMEMORYFUNCS = 39,
};

typedef RsEventStatus (*RsInputEventHandler)(RsEvent event, void *param);

struct RsInputDevice
{
    RsInputDeviceType inputDeviceType;
    i32 used;
    RsInputEventHandler inputEventHandler;
};
CHECKSIZE(RsInputDevice, 0x0C, 0x10);

struct RsGlobalType
{
    const char *appName;
    i32 maximumWidth;
    i32 maximumHeight;
    i32 maxFPS;
    i32 quit;

    void *ps; /* platform specific data */

    RsInputDevice keyboard;
    RsInputDevice mouse;
    RsInputDevice pad;
};
CHECKSIZE(RsGlobalType, 0x3C, 0x50);

DECL_OBJECT_PLT_GLOBAL(RsGlobalType, RsGlobal, BYBIT(0x67910C, 0x850240) );
#define RsGlobal RsGlobal()

#endif // __AML_PSDK_SARSGLOBAL_H

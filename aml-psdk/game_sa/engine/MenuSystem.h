#ifndef __AML_PSDK_SAMENUSYSTEM_H
#define __AML_PSDK_SAMENUSYSTEM_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CMenuSystem)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateNewMenu, _ZN11CMenuSystem13CreateNewMenuEhPcfffhhhh, u8, u8 type, char* title, float x, float y, float width, u8 columns, u8 interactive, u8 background, u8 alignment);
    DECL_FASTCALL_SIMPLE(SwitchOffMenu, _ZN11CMenuSystem13SwitchOffMenuEh, void, u8 menuId);
    DECL_FASTCALL_SIMPLE(Process, _ZN11CMenuSystem7ProcessEa, void, i8 menuId);
    DECL_FASTCALL_SIMPLE(CheckForAccept, _ZN11CMenuSystem14CheckForAcceptEh, i8, u8 menuId);
    DECL_FASTCALL_SIMPLE(CheckForSelected, _ZN11CMenuSystem16CheckForSelectedEh, i8, u8 menuId);
    DECL_FASTCALL_SIMPLE(SetActiveMenuItem, _ZN11CMenuSystem17SetActiveMenuItemEha, void, u8 menuId, i8 itemId);
    DECL_FASTCALL_SIMPLE(ActivateItems, _ZN11CMenuSystem13ActivateItemsEhhhhhhhhhhhhh, void, u8 menuId, u8 item0, u8 item1, u8 item2, u8 item3, u8 item4, u8 item5, u8 item6, u8 item7, u8 item8, u8 item9, u8 item10, u8 item11);
    DECL_FASTCALL_SIMPLE(ActivateOneItem, _ZN11CMenuSystem15ActivateOneItemEhhh, void, u8 menuId, u8 itemId, u8 enabled);
    DECL_FASTCALL_SIMPLE(HighlightOneItem, _ZN11CMenuSystem16HighlightOneItemEhhh, void, u8 menuId, u8 itemId, u8 highlighted);
    DECL_FASTCALL_SIMPLE(SetColumnHeader, _ZN11CMenuSystem15SetColumnHeaderEhhPc, void, u8 menuId, u8 column, char* title);
    DECL_FASTCALL_SIMPLE(SetDPadInput, _ZN11CMenuSystem12SetDPadInputEhh, void, u8 menuId, u8 enabled);
    DECL_FASTCALL_SIMPLE(GetMenuPosition, _ZN11CMenuSystem15GetMenuPositionEhPfS0_, void, u8 menuId, float* x, float* y);
    DECL_FASTCALL_SIMPLE(InsertOneMenuItem, _ZN11CMenuSystem17InsertOneMenuItemEhhhPc, void, u8 menuId, u8 column, u8 row, char* text);
    DECL_FASTCALL_SIMPLE(InsertOneMenuItemWithNumber, _ZN11CMenuSystem27InsertOneMenuItemWithNumberEhhhPcii, void, u8 menuId, u8 column, u8 row, char* text, i32 number1, i32 number2);
    DECL_FASTCALL_SIMPLE(InsertMenu, _ZN11CMenuSystem10InsertMenuEhhPcS0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_S0_, void, u8 menuId, u8 column, char* title, char* item0, char* item1, char* item2, char* item3, char* item4, char* item5, char* item6, char* item7, char* item8, char* item9, char* item10, char* item11);
    DECL_FASTCALL_SIMPLE(SetColumnWidth, _ZN11CMenuSystem14SetColumnWidthEhht, void, u8 menuId, u8 column, u16 width);
    DECL_FASTCALL_SIMPLE(SetColumnOrientation, _ZN11CMenuSystem20SetColumnOrientationEhhh, void, u8 menuId, u8 column, u8 alignment);
    DECL_FASTCALL_SIMPLE(SetHeaderOrientation, _ZN11CMenuSystem20SetHeaderOrientationEhhh, void, u8 menuId, u8 column, u8 alignment);
    DECL_FASTCALL_SIMPLE(GetCarColourFromGrid, _ZN11CMenuSystem20GetCarColourFromGridEhh, u8, u8 menuId, u8 row);
    DECL_FASTCALL_SIMPLE(FindCarColourFromGrid, _ZN11CMenuSystem21FindCarColourFromGridEhh, u8, u8 menuId, u8 color);
    DECL_FASTCALL_SIMPLE(IsCarColourInGrid, _ZN11CMenuSystem17IsCarColourInGridEhh, bool, u8 menuId, u8 color);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CMenuSystem10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Display, _ZN11CMenuSystem7DisplayEhh, void, u8 menuId, u8 background);
    DECL_FASTCALL_SIMPLE(DisplayStandardMenu, _ZN11CMenuSystem19DisplayStandardMenuEhh, void, u8 menuId, u8 background);
    DECL_FASTCALL_SIMPLE(DisplayGridMenu, _ZN11CMenuSystem15DisplayGridMenuEhh, void, u8 menuId, u8 background);
    DECL_FASTCALL_SIMPLE(Input, _ZN11CMenuSystem5InputEh, void, u8 menuId);
    DECL_FASTCALL_SIMPLE(InputStandardMenu, _ZN11CMenuSystem17InputStandardMenuEh, void, u8 menuId);
    DECL_FASTCALL_SIMPLE(InputGridMenu, _ZN11CMenuSystem13InputGridMenuEh, void, u8 menuId);
    DECL_FASTCALL_SIMPLE(FillGridWithCarColours, _ZN11CMenuSystem22FillGridWithCarColoursEh, void, u8 menuId);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(u8, MenuInUse, BYBIT(0x676df4, 0x84bc30));
    DECL_OBJECT_PLT(i8, CurrentMenuInUse, BYBIT(0x676a84, 0x84b550));
    DECL_OBJECT_PLT(u8, num_menus_in_use, BYBIT(0x6762c8, 0x84a5f0));

DECL_CLASS_END()
CHECKSIZE(CMenuSystem, 0x1, 0x1);

#endif // __AML_PSDK_SAMENUSYSTEM_H

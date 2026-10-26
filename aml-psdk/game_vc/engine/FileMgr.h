#ifndef __AML_PSDK_VCFILEMGR_H
#define __AML_PSDK_VCFILEMGR_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CFileMgr)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN8CFileMgr10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ChangeDir, _ZN8CFileMgr9ChangeDirEPKc, void, const char* directory);
    DECL_FASTCALL_SIMPLE(SetDir, _ZN8CFileMgr6SetDirEPKc, void, const char* directory);
    DECL_FASTCALL_SIMPLE(SetDirMyDocuments, _ZN8CFileMgr17SetDirMyDocumentsEv, void);
    // The buffer needs bufferSize + 1 bytes for the trailing zero.
    DECL_FASTCALL_SIMPLE(LoadFile, _ZN8CFileMgr8LoadFileEPKcPhiS1_, i32, const char* filename, u8* buffer, i32 bufferSize, const char* mode);
    DECL_FASTCALL_SIMPLE(LoadTextFile, _ZN8CFileMgr12LoadTextFileEPKcPhi, i32, const char* filename, u8* buffer, i32 bufferSize);
    DECL_FASTCALL_SIMPLE(OpenFile, _ZN8CFileMgr8OpenFileEPKcS1_, FILESTREAM, const char* filename, const char* mode);
    DECL_FASTCALL_SIMPLE(OpenUserFile, _ZN8CFileMgr12OpenUserFileEPKcS1_, FILESTREAM, const char* filename, const char* mode);
    DECL_FASTCALL_SIMPLE(OpenFileForWriting, _ZN8CFileMgr18OpenFileForWritingEPKc, FILESTREAM, const char* filename);
    #ifdef AML64
        DECL_FASTCALL_SIMPLE(Read, _ZN8CFileMgr4ReadEyPci, i32, FILESTREAM file, char* buffer, i32 size);
        DECL_FASTCALL_SIMPLE(Write, _ZN8CFileMgr5WriteEyPci, i32, FILESTREAM file, char* buffer, i32 size);
        DECL_FASTCALL_SIMPLE(Seek, _ZN8CFileMgr4SeekEyii, bool, FILESTREAM file, i32 offset, i32 origin);
        DECL_FASTCALL_SIMPLE(ReadLine, _ZN8CFileMgr8ReadLineEyPci, bool, FILESTREAM file, char* line, i32 maxLength);
        DECL_FASTCALL_SIMPLE(CloseFile, _ZN8CFileMgr9CloseFileEy, i32, FILESTREAM file);
    #else
        DECL_FASTCALL_SIMPLE(Read, _ZN8CFileMgr4ReadEjPci, i32, FILESTREAM file, char* buffer, i32 size);
        DECL_FASTCALL_SIMPLE(Write, _ZN8CFileMgr5WriteEjPci, i32, FILESTREAM file, char* buffer, i32 size);
        DECL_FASTCALL_SIMPLE(Seek, _ZN8CFileMgr4SeekEjii, bool, FILESTREAM file, i32 offset, i32 origin);
        DECL_FASTCALL_SIMPLE(ReadLine, _ZN8CFileMgr8ReadLineEjPci, bool, FILESTREAM file, char* line, i32 maxLength);
        DECL_FASTCALL_SIMPLE(CloseFile, _ZN8CFileMgr9CloseFileEj, i32, FILESTREAM file);
    #endif

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(char, ms_rootDirName, BYBIT(0x394C34, 0x577938));
    DECL_OBJECT_ARRAY_PLT(char, ms_dirName, BYBIT(0x3944BC, 0x576AD0));
DECL_CLASS_END()

#define ms_rootDirName ms_rootDirName()
#define ms_dirName ms_dirName()

#endif // __AML_PSDK_VCFILEMGR_H

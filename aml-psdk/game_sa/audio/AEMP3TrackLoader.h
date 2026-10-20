#ifndef __AML_PSDK_SAAEMP3TRACKLOADER_H
#define __AML_PSDK_SAAEMP3TRACKLOADER_H

#include <aml-psdk/game_sa/audio/AEDataStream.h>
#include <aml-psdk/game_sa/base/Lists.h>

struct ZIPFile;

DECL_CLASS(tTrackLookup)
    // Member values
    u8 PackFile;
    u32 FileOffset;
    u32 NumBytes;
DECL_CLASS_END()
CHECKSIZE(tTrackLookup, 0xc, 0xc);

DECL_CLASS(tStreamPackFile)
    // Member values
    char BaseFilename[9];
    u32 FileLSN;
DECL_CLASS_END()
CHECKSIZE(tStreamPackFile, 0x10, 0x10);

DECL_CLASS(CAEMP3TrackLoader)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEMP3TrackLoader, _ZN17CAEMP3TrackLoaderC2Ev);
    DECL_DTORCALL(CAEMP3TrackLoader, _ZN17CAEMP3TrackLoaderD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(GetDataStream, _ZN17CAEMP3TrackLoader13GetDataStreamEj, CAEDataStream*, u32 trackId)
    DECL_THISCALL_TAIL(GetDataStream, trackId)
    DECL_THISCALL_SIMPLE(Initialise, _ZN17CAEMP3TrackLoader10InitialiseEv, bool);
    DECL_THISCALL_SIMPLE(LoadTrackLookupTable, _ZN17CAEMP3TrackLoader20LoadTrackLookupTableEv, bool);
    DECL_THISCALL_SIMPLE(LoadStreamPackTable, _ZN17CAEMP3TrackLoader19LoadStreamPackTableEv, bool);

    // Member values
    bool m_bInitialised;
    u32 m_numTracks;
    u32 m_numPacks;
    tTrackLookup* m_pTrackLookupTable;
    tStreamPackFile* m_pStreamPackTable;
    FILESTREAM headerFile;
    OSArray<ZIPFile *> zipFiles;
DECL_CLASS_END()
CHECKSIZE(CAEMP3TrackLoader, 0x24, 0x38);

#endif // __AML_PSDK_SAAEMP3TRACKLOADER_H

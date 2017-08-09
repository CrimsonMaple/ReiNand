/*
*   memory.c
*       by Reisyukaku
*   Copyright (c) 2015 All Rights Reserved
*/
#include "memory.h"

uPtr old_memsearch(const void *startPos, const void *pattern, u32 searchSize, u32 patternSize){
    if(!searchSize) return 0;
    for (void *pos = startPos + searchSize - patternSize; pos >= startPos; pos--) {
        if (memcmp(pos, pattern, patternSize) == 0) return (uPtr)pos;
    }
    return 0;
}

u8 *memsearch(u8 *startPos, const void *pattern, u32 size, u32 patternSize)
{
    const u8 *patternc = (const u8 *)pattern;
    u32 table[256];

    //Preprocessing
    for(u32 i = 0; i < 256; i++)
        table[i] = patternSize;
    for(u32 i = 0; i < patternSize - 1; i++)
        table[patternc[i]] = patternSize - i - 1;

    //Searching
    u32 j = 0;
    while(j <= size - patternSize)
    {
        u8 c = startPos[j + patternSize - 1];
        if(patternc[patternSize - 1] == c && memcmp(pattern, startPos + j, patternSize - 1) == 0)
            return startPos + j;
        j += table[c];
    }

    return NULL;
}
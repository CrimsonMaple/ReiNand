/*
*   fc.h
*       by Reisyukaku
*   Copyright (c) 2015 All Rights Reserved
*/

#ifndef FS_INC
#define FS_INC

#include "types.h"

u8 mountSD(void);
u8 mountNand(void);
u8 unmountSD(void);
u8 unmountNand(void);
u8 fopen(const void *filename, const char *mode);
void fclose(void);
void fseek(u32 offset);
u8 eof(void);
Size fsize(void);
Size fwrite(const void *buffer, Size elementSize, Size elementCnt);
Size fread(const void *buffer, Size elementSize, Size elementCnt);
void debugWrite(const char *filename, char *buffer, Size size);
u32 lumaFileRead(void *dest, const char *path, u32 maxSize);
u32 firmRead(u8 *dest, u32 firm);

#endif
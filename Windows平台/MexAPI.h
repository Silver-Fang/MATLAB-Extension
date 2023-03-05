#pragma once
#include <Mex工具.h>
using namespace Mex工具;

//SHFileOperation

#ifdef CopyFile
#undef CopyFile
#endif
API声明(CopyFile);
API声明(Delete);
#ifdef MoveFile
#undef MoveFile
#endif
API声明(MoveFile);

//LibZip

API声明(ZipOpen);
API声明(ZipNameLocate);
API声明(ZipFopen);
API声明(ZipFread);
API声明(ZipFclose);
API声明(ZipDiscard);
API声明(ZipGetSize);
API声明(ZipGetName);
API声明(ZipGetNumEntries);

//File

API声明(File_Create);
API声明(File_GetSize);
API声明(File_Read);
API声明(File_SetEnd);
API声明(File_SetPointer);
API声明(File_Write);
API声明(File_Close);

//MemoryMapping

API声明(MemoryMapping_Create);
API声明(MemoryMapping_View);
API声明(MemoryMapping_Unview);
API声明(MemoryMapping_Close);

//Pointer

API声明(Pointer_Allocate);
API声明(Pointer_Read);
API声明(Pointer_Write);
API声明(Pointer_Copy);
API声明(Pointer_Release);

//杂项

API声明(TypeCast);
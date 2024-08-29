#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"

int getFileSize(char* fileName);
numberList_t readNumberBinaryFile(char* fileName);

#endif // FILEMANAGER_H

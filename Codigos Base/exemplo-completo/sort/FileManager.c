#include "FileManager.h"

int getFileSize(char* fileName)
{
    FILE* pFile;
    pFile = fopen(fileName, "rb");

    // checking if the file exist or not
    if (pFile == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(pFile, 0, SEEK_END);

    // calculating the size of the file
    long int fileSize = ftell(pFile);
    fclose(pFile);
    return fileSize;
}

numberList_t readNumberBinaryFile(char* fileName)
{
    numberList_t numberList;
    FILE* pFile;

    numberList.listSize = getFileSize(fileName)/sizeof(int);

    pFile = fopen(fileName, "rb");
    size_t result;

    // checking if the file exist or not
    if (pFile == NULL) {
        printf("File Not Found!\n");
    }

    numberList.numbers = (int*) malloc(sizeof(int)*numberList.listSize);

    result = fread(numberList.numbers, sizeof(int), numberList.listSize, pFile);
    if (result != numberList.listSize)
        printf("Reading error\n");
    // closing the file
    fclose(pFile);
    return numberList;
}


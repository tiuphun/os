#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");
TCHAR szMsg[] = TEXT("Message from first process.");

int _tmain() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    hMapFile = CreateFileMapping(
                INVALID_HANDLE_VALUE,   // use paging file
                NULL,                   // default security
                PAGE_READWRITE,         // read/write access
                0,                      // maximum object size (high-order DWORD)
                BUF_SIZE,               // maximum object size (low-order DWORD)
                szName);                // name of mapping object
    if (hMapFile == NULL) {
        _tprintf(TEXT("Could not create file mapping object (%d).\n"), GetLastError());
        return 1;
    }
    pBuf = (LPCTSTR) MapViewOfFile(hMapFile,
                                    FILE_MAP_ALL_ACCESS,
                                    0,
                                    0
                                    BUF_SIZE);
}
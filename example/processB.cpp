#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");

int _tmain()
{
   HANDLE hMapFile;
   LPCTSTR pBuf;
   char Msg[255];
   hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   szName);               // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);

   if (pBuf == NULL)
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);

      return 1;
   }
   //printf("Nhan thong diep tu tien trinh A:%s",pBuf);
   MessageBox(NULL, pBuf, TEXT("ProcessB"), MB_OK);
   printf("Nhap thong diep de gui den tien trinh A");
   scanf("%255[^\n]",Msg);
   CopyMemory((PVOID)pBuf, Msg, (_tcslen(Msg) * sizeof(char)));
    printf("Thong diep da gui den  tien trinh A");
   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);
   getch();
   return 0;
}

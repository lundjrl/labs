#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
   DIR *dirPtr;
   struct dirent *entryPtr;

   dirPtr = opendir (".");

   while ((entryPtr = readdir (dirPtr))){
      printf ("size: %-20d  name:%-20s\n",entryPtr->d_reclen, entryPtr->d_name);
   }
   closedir (dirPtr);
   return 0;
} 

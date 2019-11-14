#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]){

    DIR *dirPtr;
    struct dirent *entryPtr;
    struct stat statBuf;
    if(argv[2] == NULL){
        dirPtr = opendir(".");
    } else {
        dirPtr = opendir(argv[2]);
    }

    while((entryPtr = readdir (dirPtr))){
        if(strcmp(argv[1], "-n")){
//            printf("Permissions: %-10s\n 
        }
        if((strcmp(argv[1], "-i")) == 0){
            printf ("inode: %-10lu  name: %-10s\n",entryPtr->d_ino, entryPtr->d_name);
        }
        else{
        printf("name: %-20s\n", entryPtr->d_name);
        }
    }   


}

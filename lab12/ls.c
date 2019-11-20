#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){

    DIR *dirPtr;
    int multiArgs = 1;
    long totalBlocks = 0;
    struct dirent *entryPtr;
    struct stat statBuf;
    struct tm timeStruct;
    char buf[80];

    // See how many arguments are passed and if it is an option or directory
    // Must pass in option and then directory

    if(argc == 1){
      dirPtr = opendir(".");
      multiArgs = 0;
    } else if(argc == 2){
      if(argv[1] != NULL && argv[1][0] != '-'){
        dirPtr = opendir(argv[1]);
        printf("Here open: %s\n", argv[1]);
      } else if(argv[1] != NULL && argv[1][0] == '-'){
        dirPtr = opendir(".");
      }
    } else if(argc == 3){
        if(argv[2] == NULL){
          dirPtr = opendir(".");
        } else {
          dirPtr = opendir(argv[2]);
        }
    } else {
        printf("Too many arguments provided\n");
        exit(1);
    }

    while((entryPtr = readdir(dirPtr))){
      if(multiArgs){
        if(strcmp(argv[1], "-n") == 0){

          if((strcmp(entryPtr->d_name, ".") == 0) || (strcmp(entryPtr->d_name, "..") == 0)){
            continue;
          }

           stat(entryPtr->d_name, &statBuf);
           printf((S_ISDIR(statBuf.st_mode)) ? "d" : "-");
           printf((statBuf.st_mode & S_IRUSR) ? "r" : "-");
           printf((statBuf.st_mode & S_IWUSR) ? "w" : "-");
           printf((statBuf.st_mode & S_IXUSR) ? "x" : "-");
           printf((statBuf.st_mode & S_IRGRP) ? "r" : "-");
           printf((statBuf.st_mode & S_IWGRP) ? "w" : "-");
           printf((statBuf.st_mode & S_IXGRP) ? "s" : "-");
           printf((statBuf.st_mode & S_IROTH) ? "r" : "-");
           printf((statBuf.st_mode & S_IWOTH) ? "w" : "-");
           printf((statBuf.st_mode & S_IXOTH) ? "x" : "-");
           printf("\t%ld\t", statBuf.st_nlink);
           printf("%d\t", statBuf.st_uid);
           printf("%d\t", statBuf.st_gid);

           totalBlocks += statBuf.st_blocks;
           printf("%ld\t", statBuf.st_size);

           timeStruct = *localtime(&statBuf.st_mtim.tv_sec);
           strftime(buf, sizeof(buf), "%m %d %H:%M", &timeStruct);
           printf("%s\t", buf);

           printf("%-10s\n", entryPtr->d_name);
        }
        if((strcmp(argv[1], "-i")) == 0){
          printf ("inode: %-10lu  name: %-10s\n",entryPtr->d_ino, entryPtr->d_name);
        }
      }
      else{
        printf("name: %-20s\n", entryPtr->d_name);
      }
    }
    closedir(dirPtr);

    if(multiArgs){
      if(strcmp(argv[1], "-n") == 0){
        printf("Total: %ld\n", (totalBlocks/2));
      }
    }


    exit(1);

}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

  if(argc < 3){
     printf("Please use format: %s <src_file> <dest_file>\n",argv[0]);
     exit(0);
  }
  if((strcmp(argv[1], "-s")) == 0){
    if(symlink(argv[2], argv[3]) == -1){
       printf("Link s Error\n");
       exit(1);
    }
    else{
       printf("Symlink created\n");
    }
  }else{
    if(link(argv[1], argv[2]) == -1){
       printf("Link Error\n");
       exit(1);
    }
  }

  printf("Files Linked\n");

  return 0;
}

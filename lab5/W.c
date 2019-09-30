#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdbool.h>

#include "shared.h"


void handle(int sig){
    printf("Goodbye\n");
    exit(0);
}


int main(int argc, char* argv[]){
    
    int shmId;
    struct shared *shmSTRT;
    key_t shmKEY = ftok("R.c", 'Z');

    signal(SIGINT, handle);
 
    if ((shmId = shmget (shmKEY, sizeof(struct shared), IPC_CREAT|S_IRUSR|S_IWUSR)) < 0){
      perror("ERROR CREATING MEMORY\n");
        exit(1);
    }
    if ((shmSTRT = shmat (shmId, 0, 0)) == (void*) -1){
        perror("Can't attach to memory\n");
        exit(1);
    }
    printf("%d", shmId); 
    while(1){
        printf("What would you like the world to see? ");
        scanf("%s", shmSTRT->message);
        printf("%s\n", shmSTRT->message);
        shmSTRT->turn = 'r';
        //Notify the read that there is new data
       
    }

    return 0;
}



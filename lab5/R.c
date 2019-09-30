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
 
    if ((shmId = shmget (shmKEY, sizeof(struct shared), S_IRUSR|S_IWUSR)) < 0){
      perror("ERROR CREATING MEMORY\n");
        exit(1);
    }
    if ((shmSTRT = shmat (shmId, 0, 0)) == (void*) -1){
        perror("Can't attach to memory\n");
        exit(1);
    }
    printf("%d", shmId);
    while(1){
        // See if we can read
        if(shmSTRT->turn == 'r')
        printf("Message recieved: %s", shmSTRT->message);

        // Finished, time to write
        shmSTRT->turn = 'w';

       
    }
    
    return 0;
}



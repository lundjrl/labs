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
    printf(" Goodbye\n");
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

    while(1){
        // See if we can read
        // Wait
        while (shmSTRT->turn == 'w')
          ;

        printf("Message recieved: %s\n", shmSTRT->message);
        // Finished, time to write
        shmSTRT->turn = 'w';
        
        if(shmSTRT->turn == 'r'){
            printf("What would you like the world to see? ");
            fgets(shmSTRT->message, sizeof(shmSTRT->message), stdin);
            shmSTRT->turn = 'w';
        }
    }

    if (shmdt (shmSTRT) < 0) {
      perror ("just can't let go\n");
      exit (1);
    }
    if (shmctl (shmId, IPC_RMID, 0) < 0) {
      perror ("can't deallocate\n");
      exit(1);
    }

    return 0;
}

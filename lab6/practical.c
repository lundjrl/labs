#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/sem.h>

#define SIZE 16

//sem_t mutex;

//FREE YOUR RESOURCES, MAKE SURE EVERY LINE OF CODE IS USED
int main (int argc, char* argv[])
{
   int status;
   long int i, loop, temp, *shmPtr;
   int shmId;
   struct sembuf semabuf;
   pid_t pid;

   semabuf.sem_num = 0;
   semabuf.sem_op = 1;
   semabuf.sem_flg = 0;

   loop = atoi(argv[1]);

   if ((shmId = shmget (IPC_PRIVATE, SIZE, IPC_CREAT|S_IRUSR|S_IWUSR)) < 0) {
      perror ("i can't get no..\n");
      exit (1);
   }
   if ((shmPtr = shmat (shmId, 0, 0)) == (void*) -1) {
      perror ("can't attach\n");
      exit (1);
   }

   shmPtr[0] = 0;
   shmPtr[1] = 1;
   if (!(pid = fork())) {
      for (i=0; i<loop; i++) {
        semabuf.sem_op = -1;
        semabuf.sem_flg = SEM_UNDO;
        semop(shmId, &semabuf, 1);

        temp = shmPtr[0];
        shmPtr[0] = shmPtr[1];
        shmPtr[1] = temp;

        semabuf.sem_op = 1;
        semop(shmId, &semabuf, 1);
      }
      if (shmdt (shmPtr) < 0) {
         perror ("just can't let go\n");
         exit (1);
      }
      exit(0);
   }
   else{
      for (i=0; i<loop; i++) {
        semabuf.sem_op = -1;
        semabuf.sem_flg = SEM_UNDO;
        semop(shmId, &semabuf, 1);

        temp = shmPtr[1];
        shmPtr[1] = shmPtr[0];
        shmPtr[0] = temp;

        semabuf.sem_op = 1;
        semop(shmId, &semabuf, 1);
      }
    }
   wait (&status);
   printf ("values: %li\t%li\n", shmPtr[0], shmPtr[1]);

   if (shmdt (shmPtr) < 0) {
      perror ("just can't let go\n");
      exit (1);
   }
   if (shmctl (shmId, IPC_RMID, 0) < 0) {
      perror ("can't deallocate\n");
      exit(1);
   }

   semctl(shmId, 0, IPC_RMID);

   return 0;
}

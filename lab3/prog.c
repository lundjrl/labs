#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

//Authors: James Lund, Zachary Thomas

void handler(int sig){
  if (sig == SIGUSR1){
    printf(" Caught signal SIGUSR1\n");
  }
  else if (sig == SIGUSR2){
    printf(" Caught signal SIGUSR2\n");
  }
  else if (sig == SIGINT){
    printf("That's it. I'm shutting you down...\n");
    exit(0);
  }
  else{
    printf("Error");
  }
}


int main(){
  pid_t parent, pid;
  int sleptfor;
  
  parent = getpid();
  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);

  if ((pid =  fork()) < 0){
    perror("fork failed");
    exit(1);
  }
  else if (pid == 0){
    //Child process
    while(1){
      sleptfor = rand() % 5 + 1;
      if (sleptfor % 2 == 0){
        sleep(sleptfor);
        kill(parent, SIGUSR1);
      }
      else{
        sleep(sleptfor);
        kill(parent, SIGUSR2);
      }
    }
  }
  else{
    //Parent process
    signal(SIGINT, handler);
    printf("spawned child PID# %d\n", pid);

    while(1){
      printf("waiting...\t");
      pause();
    }
  }
  return 0;
}

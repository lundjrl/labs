#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void handler(int sig){
  if (sig == SIGUSR1){
    printf(" Caught signal SIGUSR1\n");
  }
  else if (sig == SIGUSR2){
    printf(" Caught signal SIGUSR2\n");
  }
  else if (sig == SIGINT){
    printf(" Shutting down...\n");
    exit(0);
  }
  else{
    printf(stderr, "Signal error\n");
  }
}


int main(){
  pid_t parent, pid;
  int status, sleptfor;
  time_t t;
  int fd[2];

  while(1){

	  parent = getpid();
	  signal(SIGUSR1, handler);
	  signal(SIGUSR2, handler);
	  signal(SIGINT, handler);

	  if ((pid =  fork()) < 0){
	    perror("fork failed");
	    exit(1);
	  }

	  else if (pid == 0){
	    //Child process
	    srand((unsigned) time(&t));
	    sleptfor = (rand() % 5);
	    if (sleptfor % 2 == 0){
	      sleep(sleptfor);
	      kill(parent, SIGUSR1);
	    }
	    else{
	      kill(parent, SIGUSR2);
	      exit(0);
	    }
	  }
	  else{
	  //Parent process
	  printf("Waiting on child...");
	  wait(&status);
	  }
  }
  return 0;
}

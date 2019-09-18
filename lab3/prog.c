#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig){
  if (sig == SIGUSR1){
    printf(" Caught signal %d\n", sig);
    kill(0, sig);
  }
  else if (sig == SIGUSR2){
    printf(" Caught signal %d\n", sig);
    kill(0, sig);
  }
  else if (sig == SIGINT){
    printf(" Caught signal %d\n", sig);
    kill(0, sig);
  }
  printf("handler");
}

int main(){

  pid_t pid;
  time_t t;
  int fd[2];

  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
  signal(SIGINT, handler);

  if (pipe (fd) < 0) { 
        perror ("plumbing problem"); 
        exit(1); 
  } 

  if ((pid =  fork()) < 0){
    perror("fork failed");
    exit(1);
  }

  else if (pid == 0){
    //Child process
    srand((unsigned) time(&t));
    wait(rand() % 5);
    printf("child");
    //kill(pid, SIGUSR2);
  }
  else{
  //Parent process
  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
  sleep(10);
  }
  return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int);

void handler(int sig){
    printf(" Caught signal %d\n", sig);
    kill(0, sig);
}

int main(){

  pid_t pid;
  //pid = fork();

  if ((pid =  fork()) < 0){
    perror("fork failed");
    exit(1);
  }

  else if (pid == 0){
    //Child process
    printf("child");
    sleep(5);
    signal(SIGINT, handler);
  }
  else{
  //Parent process
  //signal(SIGINT, handler);
  sleep(10);
  }
  return 0;
}

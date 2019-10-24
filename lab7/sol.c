#include <stdio.h>
#include <bits/posix1_lim.h>
#include <sys/sem.h>

int main()
{
  int semid;
  int i = 1;
  semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 00600);
  semctl(semid,0,SETVAL,1);

  while(1)
  {
    if(semctl(semid,0,SETVAL,i) == -1)
    {
      printf("Max sem value: %d\n", i);
      break;
    }
    i++;
  }
  semctl(semid,0,IPC_RMID);
  return 0;
}

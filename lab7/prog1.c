#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("%d",sysconf(SEM_NSEMS_MAX));

  exit(0);
}
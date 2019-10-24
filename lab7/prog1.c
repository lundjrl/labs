#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
  printf("%ld\n",sysconf(_POSIX_SEM_VALUE_MAX));
  exit(0);
}

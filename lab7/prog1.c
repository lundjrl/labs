#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]) {
  printf("%ld\n",sysconf(_SC_PAGESIZE));

  exit(0);
}

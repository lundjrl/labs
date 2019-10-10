#include <limits.h>

int main(int argc, char *argv[]) {
  printf("%d",sysconf(SEM_NSEMS_MAX))

  exit(0);
}
#include <unistd.h>
#include <stdio.h>

int getpagesize(void);

int main(int argc, char const *argv[])
{
  /* Page size (bytes) */
  long sz = sysconf(_SC_PAGESIZE);
  printf("%ld \n", sz);

  /* Physical pages in system */
  long pg = sysconf(_SC_PHYS_PAGES);
  printf("%lu\n", pg);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
  char *data1;
  char dataCopy[16];

  data1 = malloc (SIZE);
  printf ("Please input username: ");
  scanf ("%s", dataCopy);

  printf ("you entered: %s\n", dataCopy);
  free (data1);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
  char *data1;

  data1 = malloc (SIZE);
  printf ("Please input username (Only 15 characters will be saved): ");
  fgets(data1, SIZE, stdin);
  printf ("you entered: %s\n", data1);
  free (data1);
  return 0;
}

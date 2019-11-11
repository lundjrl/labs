#include <stdio.h>
#include <stdlib.h>

#define COEFFICIENT 2
#define KB 1024
#define LOOP 200

int main()
{
   int count, *intPtr;

   long int i, j, dim = COEFFICIENT * KB;

   //malloc enough mem
   if ((intPtr = malloc (dim * dim * sizeof(int))) == 0) {
      perror ("totally out of space");
      exit (1);
   }
   //Makes page persist in memory until we are done. 
   for (count=1; count<=LOOP; count++)
      //rows
      for (i=0; i<dim; i++)
         //columns
         for (j=0; j<dim; j++)
            intPtr[i * dim + j] = (i + j) % count;

   free (intPtr);
   return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command[80] = "date +%A";
    char name[32];

    printf("Enter your nickname: ");
    gets(name);
    printf("Hi, %s.  Today is: ", name);
    //fflush(stdout);

    printf("command: %s", command);
    fflush(stdout);
    system(command);
    return 0;
} 

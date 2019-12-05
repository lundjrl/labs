#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[32];
    char command[64];

    printf("Enter your eos username: ");
    scanf("%s", name);
    sprintf(command, "groups %s", name);
    system(command);
    return 0;
}

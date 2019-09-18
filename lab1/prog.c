#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
        char *hostname;
        struct passwd *password;
        printf("User is: %s\n", getlogin());
        printf("UID is: %d\n", getuid());
        printf("GID is: %d\n", getgid());
        hostname = malloc (32);
        gethostname(hostname, 32);
        printf("Host is: %s\n\n", hostname);
        free(hostname);
        password = getpwuid(getuid());

        int i = 1;
        password = getpwent();
        while(i < 6){
                printf("entry %d: %s\n", i, password->pw_name);
                password = getpwent();
                i++;
        }
        char *input;
        input = malloc(32);
        printf("\nEnvironment variable desired? ");
        scanf("%s", input);
        printf("\nValue is: %s\n", getenv(input));
        free(input);
        return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){
	char input[50];
	int status;
	printf("Please input a file: \n");
	fgets(input, 50, stdin);
	
	pthread_t thread1;

	if ((status = pthread_create (&thread1, NULL, somefunc, info passed)) != 0 ){
		fprintf (stderr, "failed to create thread %d: %s\n", status strerror(status));
		exit(1);
	}


}

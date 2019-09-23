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
	// while(1){
		if ((status = pthread_create (&thread1, NULL, somefunc, input)) != 0 ){
			fprintf (stderr, "Failed to create thread %d: %s\n", status strerror(status));
			exit(1);
		}
	}

}

int processfile(int stufffromdispatcher){
	pthread_t wt1;
	int status;
	printf("Processing file from thread %d\n", stufffromdispatcher);
	//do stuff for creating worker threads
	if ((status = pthread_create(&wt1, NULL, function to do, stufffromdispatcher)) != 0){
		fprintf(stderr, "Failed to create worker. Error %d: %s\n", status, stderror(status));
		exit(1);
	return 0;
}

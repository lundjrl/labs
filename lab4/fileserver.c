#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//Global shared data??
void* processFile(void* arg);

void* createWorker(void* arg);

void handler(int sig){
	//Print out basic stats i.e. total # of file requests received
}

int main(int argc, char* argv[]){

	char input[50];
	int status;
	FILE *fp;
	while(!signal(SIGINT, handler)){
	//User input and prompt
	printf("Please input a file: \n");
	fgets(input, 50, stdin);
	
	//Thread ID
	pthread_t dispatcher;
	
		if ((status = pthread_create (&dispatcher, NULL, createWorker, input)) != 0 ){
			fprintf (stderr, "Failed to create thread %d: %s\n", status, strerror(status));
			exit(1);
		}
	}

	return 0;
}

void* createWorker(void* arg){
	pthread_t wt1;
	int status;
	int random;
	int probability;

	printf("Creating worker named %d:  %s\n", &wt1);
	if ((status = pthread_create(&wt1, NULL, processFile, input)) != 0){
		fprintf(stderr, "Failed to create worker. Error %d: %s\n", status, stderror(status));
		exit(1);
	}

	return NULL;
}

void* processFile(void* arg){
	int status, probability, random;

	probability = (rand() % 5 + 1);
	if (probability == 1){ //not found requested file
		random = (rand() % (10 - 7 + 1)) + 7;
		sleep(random);
		//block thread
		//while(someconditional)
		//;
	}
	else{ //Finds the requested file in a timely manner
		sleep(1);
		random = 1;
	printf("Found file %d", input, " In %d", random, " seconds!\n");
	return NULL;
}


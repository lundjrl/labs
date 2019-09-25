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

char name[10] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};


int main(int argc, char* argv[]){

	//char input[50];
	int status;
	char *buffer = (malloc(500)); 

	while(!signal(SIGINT, handler)){
	//User input and prompt
	printf("Please input a file: \n");
	fgets(buffer, 50, stdin);
	
	//Thread ID
	pthread_t dispatcher;
	
		if ((status = pthread_create (&dispatcher, NULL, createWorker, (void *)&buffer)) != 0 ){
			fprintf (stderr, "Failed to create thread %d: %s\n", status, strerror(status));
			exit(1);
		}
	}

	return 0;
}

void* createWorker(void* file){
	pthread_t wt1;
	int status;

	//char *name_ptr = (char *) file;
	// Make a loop for amount of child threads spawned and set name from array created above. 

	printf("Creating worker named:  %c\n", file);
	if ((status = pthread_create(&wt1, NULL, processFile, file)) != 0){
		fprintf(stderr, "Failed to create worker. Error %d: %d\n", status, stderror(status));
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

	//Input down below should be the filepointer we pass via threads
	printf("Found file %d", arg, " In %d", random, " seconds!\n");
	}
	return NULL;
}


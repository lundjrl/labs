#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//Global shared data and function prototypes
int numberOfRequests = 0;

void* processFile(void* arg);

void* createWorker(void* arg);

void handler(int sig){
	//Print out basic stats i.e. total # of file requests received
	printf("\nNumber of file requests today: %d\n", numberOfRequests);
	printf("Shutting down gracefully...\n");
	exit(0);
}

int main(int argc, char* argv[]){

	char input[50];
	int status;
	signal(SIGINT, handler);
	void *result;

	while(1){
	//User input and prompt
	printf("Please input a file: ");
	scanf("%s", input);

	//Thread ID
	pthread_t dispatcher;
	
	if ((status = pthread_create (&dispatcher, NULL, createWorker, &input)) != 0 ){
		fprintf (stderr, "Failed to create thread %d: %s\n", status, strerror(status));
		exit(1);
	}
	numberOfRequests++;

	//}
	if ((status = pthread_join (dispatcher, &result)) != 0){
		fprintf(stderr, "join error on dispatcher %d: %s\n", status, strerror(status));
	}
}
	return 0;
}

void* createWorker(void* arg){
	pthread_t wt1;
	int status;
	void *result2;
	char *workerName = (char *) arg;

	// Make a loop for amount of child threads spawned and set name from array created above. 

	printf("\nFinding file named:  %s\n", workerName);
	if ((status = pthread_create(&wt1, NULL, processFile, workerName)) != 0){
		fprintf(stderr, "Failed to create worker. Error %d: %s\n", status, strerror(status));
		exit(1);
	}
	if ((status = pthread_join (wt1, &result2)) != 0){
		fprintf (stderr, "join error on worker %d: %s\n", status, strerror(status));
	}
	return NULL;
}

void* processFile(void* arg){
	int probability, random;
	char fileName[20];
	strcpy(fileName, (char *) arg);
	probability = (rand() % 5 + 1);
	if (probability == 1){ //not found requested file
		random = (rand() % (10 - 7 + 1)) + 7;
		sleep(random);
	}
	else{ //Finds the requested file in a timely manner
		sleep(1);
		random = 1;
	}
	//Input down below should be the filepointer we pass via threads
	printf("\nFound file %s\n", fileName);
	return NULL;
}


//ryanh - PROG72370 - Assignment 1 - Win25

#include "user.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int testing(int qmax);

int main(int argc, char** argv) {
	if (argc != 2) {	// if there are not enough command line arguments, exit with error message
		fprintf(stderr, "usage: %s <number> \nincorrect number of parameters entered\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));	// seeding random number generator

	testing(atoi(argv[1]));	// testing function that, initializes, enqueues, dequeues, and prints a queue of randomly generated users


	return 0;
}


//it says to make a testing main(function), so I assumed to make the function in main.c
int testing(int qmax) {
	//initialize
	PQUE tail = NULL; 
	PQUE head = NULL; 
	initialize(&tail, generateUser(generateUsername(), generateLevel(), generateFaction()));

	//enqueue
	for (int i = 0; i < qmax; i++) {
		enqueue(&tail, &head, generateUser(generateUsername(), generateLevel(), generateFaction()));
	}

	//dequeue and check if empty
	while (!emptyStatus(tail)) {
		for (int i = 0; i < qmax; i++) {
			dequeue(&head, &tail);
		}
	}

	return 0;
}




//ryanh - PROG72370 - Assignment 1 - Win25

#include "user.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int testing(int qmax);

int main(int argc, char** argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <number> \nincorrect number of parameters entered\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));

	testing(atoi(argv[1]));


	return 0;
}

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




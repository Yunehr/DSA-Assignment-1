#pragma once
//ryanh - PROG72370 - Assignment 1 - Win25

#include "user.h"
#include <stdbool.h>

#define MAX_QUEUE	10

typedef struct queue {
	USER data;
	struct node* next;
}QUE, *PQUE;

//A function to initialize a blank queue
void initialize(PQUE* tail, USER data);

//A function to check if the queue is empty
bool emptyStatus(PQUE* tail);	//empty if current->next == NULL

//A function to enqueue a node	(insertion)
void enqueue(PQUE* tail, PQUE* head, USER data);

//A function to dequeue a node (delete from queue)
void dequeue(PQUE* head, PQUE* tail);

//other
void printNode(PQUE node);


//ryanh - PROG72370 - Assignment 1 - Win25

#include "queue.h"
#include "user.h"
#include <stdio.h>
#include <stdlib.h>


//A function to initialize a blank queue
void initialize(PQUE* tail, USER data) {
	PQUE newNode = (PQUE)malloc(sizeof(QUE));
	if (newNode == NULL) {
		printf("error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;	// transfer data to node
	newNode->next = *tail;
	*tail = newNode;
}

//A function to check if the queue is empty
bool emptyStatus(PQUE* tail) {
	PQUE tmp = tail;
	if (tmp->next == NULL) {	//if next item is null (1 item left) queue is empty
		return true;
	}
	return false;			//else return false
}

//A function to enqueue a node	(insertion)
void enqueue(PQUE* tail,PQUE* head, USER data) {
	PQUE newNode = (PQUE)malloc(sizeof(QUE));
	if (newNode == NULL) {
		printf("error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	if (emptyStatus(*tail)) {		// if second item (queue is empty)
		newNode->data = data;		// transfer data to node
		newNode->next = *tail;		// add node to end of queue and
		*head = *tail;				// head points to first item
		*tail = newNode;			// tail becomes new node (second item becomes tail)
	}
	else {
		newNode->data = data;
		newNode->next = *tail;	// add new node to end of queue
		*tail = newNode;		// new node becomes tail
	}
}

//A function to dequeue a node (delete from queue)
void dequeue(PQUE* head, PQUE* tail) {
	PQUE current = *tail;
	while (current != NULL) {
		if (current->next == *head) {	//if next item is front of queue
			printNode(*head);			//print front of queue

			PQUE tmp = *head;	//create temp pointer to head value
			free(tmp);			//free dynamically allocated memory

			current->next = NULL;		//set next item to null
			*head = current;			//set this item to head of queue
			
		}
		current = current->next;
	}
}

//other
void printNode(PQUE node) {
	printf("\nUser:	 %s\nLevel:	 %d\n", node->data.username, node->data.level);

	switch (node->data.faction) {
	case RED:
		printf("Faction: Red\n");
		break;
	case BLUE:
		printf("Faction: Blue\n");
		break;
	case GREEN:
		printf("Faction: Green\n");
		break;
	}
}

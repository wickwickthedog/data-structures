#ifndef SINGLY_LINKEDLIST_TEST
#define SINGLY_LINKEDLIST_TEST
#include "SinglyLinkedList.h"
#endif

#include <stdlib.h>
#include <stdio.h>

int main() {
	char *name = "DEMO LIST";
	// printf("%s\n", name);
	printf("----- START -----\n");
	SinglyLinkedList l = newSinglyLinkedList(name);
	displaySinglyLinkedList(l);
	printf("\n");	

	printf("----- TEST INSERT -----\n");
	appendToSinglyLinkedList(l, 1);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 2);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);
	printf("----- TEST INSERT DONE-----\n\n");

	printf("----- TEST REMOVE -----\n");
	removeFromSinglyLinkedList(l,4);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,1);
	displaySinglyLinkedList(l);
	printf("\n");

	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 4);
	displaySinglyLinkedList(l);
	printf("\n");

	removeFromSinglyLinkedList(l,3);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,4);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,2);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,2);
	displaySinglyLinkedList(l);
	printf("\n");

	appendToSinglyLinkedList(l, 1);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 2);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);
	printf("\n");
	printf("----- TEST REMOVE DONE -----\n\n");

	freeSinglyLinkedList(l);
	// displaySinglyLinkedList(l);
	printf("----- END -----\n");

	return EXIT_SUCCESS;
}

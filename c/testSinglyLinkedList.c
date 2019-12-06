#ifndef SINGLY_LINKEDLIST_TEST
#define SINGLY_LINKEDLIST_TEST
#include "SinglyLinkedList.h"
#endif

#include <stdlib.h>
#include <stdio.h>

int main() {
	char *name = "List 1";
	// printf("%s\n", name);
	SinglyLinkedList l = newSinglyLinkedList(name);
	displaySinglyLinkedList(l);
	printf("\n");	

	appendToSinglyLinkedList(l, 1);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 2);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);
	printf("\n");

	removeFromSinglyLinkedList(l,4);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,1);
	displaySinglyLinkedList(l);
	printf("\n");

	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 4);
	displaySinglyLinkedList(l);

	removeFromSinglyLinkedList(l,3);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,4);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,2);
	displaySinglyLinkedList(l);

	freeSinglyLinkedList(l);
	displaySinglyLinkedList(l);
	printf("\n");

	return EXIT_SUCCESS;
}

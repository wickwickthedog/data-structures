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
	
	appendToSinglyLinkedList(l, 1);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 2);
	displaySinglyLinkedList(l);
	appendToSinglyLinkedList(l, 3);
	displaySinglyLinkedList(l);

	removeFromSinglyLinkedList(l,4);
	displaySinglyLinkedList(l);
	removeFromSinglyLinkedList(l,1);
	displaySinglyLinkedList(l);

	// freeSinglyLinkedList(l);
	// displaySinglyLinkedList(l);
	return EXIT_SUCCESS;
}

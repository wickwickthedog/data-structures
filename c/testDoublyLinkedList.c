#ifndef DOUBLY_LINKEDLIST_TEST
#define DOUBLY_LINKEDLIST_TEST
#include "DoublyLinkedList.h"
#endif

#include <stdlib.h>
#include <stdio.h>

int main() {
	char *name = "DEMO LIST";
	// printf("%s\n", name);
	printf("----- START -----\n");
	DoublyLinkedList l = newDoublyLinkedList(name);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);
	printf("\n");	

	printf("----- TEST INSERT -----\n");
	char *data = "Hi!";
	insertBeforeToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);

	removeFromDoublyLinkedList(l);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);

	data = "Hello";
	insertAfterToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	data = "<3!";
	insertAfterToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	data = "Wick Wick";
	insertBeforeToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);
	printf("----- TEST INSERT DONE-----\n\n");

	printf("----- TEST REMOVE -----\n");
	removeFromDoublyLinkedList(l);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);

	removeFromDoublyLinkedList(l);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);

	removeFromDoublyLinkedList(l);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);

	removeFromDoublyLinkedList(l);
	displayDoublyLinkedList(l);
	displayReversedDoublyLinkedList(l);
	printf("----- TEST REMOVE DONE -----\n\n");

	printf("----- TEST MOVE -----\n");
	data = "Hello";
	insertAfterToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	data = "<3!";
	insertAfterToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	data = "Wick Wick";
	insertBeforeToDoublyLinkedList(l, data);
	displayDoublyLinkedList(l);
	
	int shift = -1;
	moveCurrentPtr(l, shift);
	printf("> Shift current node by %d\n", shift);
	displayDoublyLinkedList(l);
	shift = 3;
	moveCurrentPtr(l, shift);
	printf("> Shift current node by %d\n", shift);
	displayDoublyLinkedList(l);
	printf("----- TEST MOVE DONE -----\n\n");

	freeDoublyLinkedList(l);
	// displayDoublyLinkedList(l);
	// displayReversedDoublyLinkedList(l);
	printf("----- END -----\n");

	return EXIT_SUCCESS;
}

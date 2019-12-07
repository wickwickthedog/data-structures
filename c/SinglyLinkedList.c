// Written by wickwickthedog, December 2019
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include "assert.h"
#include "SinglyLinkedList.h"

// data struct for singly linked list's elem
typedef struct listNode {
	int data;
	struct listNode *next;
} Elem;

// data struct for singly linked list
struct singlyLinkedListRep {
	char *name;
	int size;
	Elem *head; 
	Elem *tail;
};

// Helper functions
static Elem *newElem(int);
static bool contains(SinglyLinkedList, int);

/** 
 * creates an empty singly linked list
 *
 * @param name of the list
 * @return ptr to an empty singly linked list
 */
SinglyLinkedList newSinglyLinkedList(char *name) {
	printf("> Attempting to create singly linked list named: %s\n", name);
	SinglyLinkedList l = malloc(sizeof(struct singlyLinkedListRep));
	assert(l != NULL);
	l -> name = name;
	l -> size = 0;
	l -> head = NULL;
	l -> tail = NULL;
	printf("Created singly linked list named: %s\n", l -> name);
	return l;
}

/** 
 * prints all elem in singly linked list
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displaySinglyLinkedList(SinglyLinkedList SL) {
	assert(SL != NULL);
	printf("%s: ", SL -> name);
	if (SL -> size == 0) {
		printf("is empty {Size of %s: %d}\n", SL -> name, SL -> size);
		return;
	}

	Elem *curr = SL -> head;
	while (curr != NULL) {
		printf("[%d] ~~> ", curr -> data);
		curr = curr -> next;
	}
	printf(" NULL {Size of %s: %d}\n", SL -> name, SL -> size);
}

/** 
 * append new elem into singly linked list 
 * (insert to the end of the list if not in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void appendToSinglyLinkedList(SinglyLinkedList SL, int data) {
	assert(SL != NULL);
	printf("> Attempting to append [%d] to the end of %s\n", data, SL -> name);
	if (contains(SL, data)) {
		printf("%s already contains [%d]\n", SL -> name, data);
		return;	
	}

	Elem *elem = newElem(data);
	if (SL -> size == 0) SL -> head = SL -> tail = elem;
	else if (SL -> size == 1) {
		SL -> head -> next = elem;
		SL -> tail = elem;
	}
	else {
		SL -> tail -> next = elem;
		SL -> tail = elem;
	}
	SL -> size ++;
	printf("Appended [%d] to the end of %s\n", elem -> data, SL -> name);
}

/** 
 * free memory for all elem and singly linked list 
 * Time Complexity : O(n) 
 *
 * @param list
 */
void freeSinglyLinkedList(SinglyLinkedList SL) {
	assert(SL != NULL);
	printf("> Attempting to free %s\n", SL -> name);
	char *name = SL -> name;

	if (SL -> size == 0) {
		free(SL);
		printf("Freed %s\n", name);
		return;
	}

	Elem *curr = SL -> head;
	while (curr != NULL) {
		Elem *temp = curr;
		curr = curr -> next;
		free(temp);
	}
	free(SL);
	printf("Freed %s\n", name);
}

/** 
 * remove elem from singly linked list 
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void removeFromSinglyLinkedList(SinglyLinkedList SL, int data) {
	assert(SL != NULL);
	printf("> Attempting to remove [%d] from %s\n", data, SL -> name);
	if (!contains(SL, data)) {
		printf("[%d] doesn't exist in %s\n", data, SL -> name);
		return;	
	}

	Elem *curr = SL -> head;
	if (curr == SL -> head && curr -> data == data) {
		Elem *temp = curr;
		SL -> head = curr -> next;
		SL -> size --;
		free(temp);
		printf("Removed [%d] from %s\n", data, SL -> name);
		return;
	}

	while (curr != NULL) {
		if (curr -> next == SL -> tail && curr -> next -> data == data) {
			Elem *temp = SL -> tail;
			curr -> next = NULL;
			SL -> tail = curr;
			SL -> size --;
			free(temp);
			printf("Removed [%d] from %s\n", data, SL -> name);
			return;
		}
		if (curr -> next != NULL && curr -> next -> data == data) {
			Elem *temp = curr -> next;
			curr -> next = curr -> next -> next;
			SL -> size --;
			free(temp);
			printf("Removed [%d] from %s\n", data, SL -> name);
			return;
		}
		curr = curr -> next;
	}
	printf("[%d] doesn't exist in %s\n", data, SL -> name);
}

/** 
 * Helper function - to create an elem node
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param data
 * @return ptr to Elem
 */
static Elem *newElem(int data) {
	Elem *new = malloc(sizeof(Elem));
	assert(new != NULL);
	new -> data = data;
	new -> next = NULL;
	return new;
}

/** 
 * Helper function - to check if list contains elem
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 * @return true if exist
 * @return false if doesn't exist
 */
static bool contains(SinglyLinkedList SL, int data) {
	Elem *curr = SL -> head;
	while (curr != NULL) {
		if (curr -> data == data) {
			return true;
		}
		curr = curr -> next;
	}
	return false;
}
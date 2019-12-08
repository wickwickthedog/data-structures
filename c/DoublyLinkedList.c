// Written by wickwickthedog, December 2019
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>
#include <string.h>
#include "DoublyLinkedList.h"

// data struct for Doubly linked list's elem
typedef struct listNode {
	char *data;
	struct listNode *prev;
	struct listNode *next;
} Elem;

// data struct for Doubly linked list
struct doublyLinkedListRep {
	char *name;
	int size;
	Elem *head;
	Elem *curr; 
	Elem *tail;
};

// Helper functions
static Elem *newElem(char *);
static bool contains(DoublyLinkedList, char *);
static bool isEmpty(DoublyLinkedList);
static int moveCurrent(DoublyLinkedList, int);

/** 
 * creates an empty Doubly linked list
 *
 * @param name of the list
 * @return ptr to an empty Doubly linked list
 */
DoublyLinkedList newDoublyLinkedList(char *name) {
	printf("> Attempting to create Doubly linked list named: %s\n", name);
	DoublyLinkedList l = malloc(sizeof(struct doublyLinkedListRep));
	assert(l != NULL);
	l -> name = name;
	l -> size = 0;
	l -> head = NULL;
	l -> curr = NULL;
	l -> tail = NULL;
	printf("Created Doubly linked list named: %s\n", l -> name);
	return l;
}

/** 
 * prints all elem in Doubly linked list
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayDoublyLinkedList(DoublyLinkedList DL) {
	assert(DL != NULL);
	printf("%s: ", DL -> name);
	if (DL -> size == 0) {
		printf("is empty {Size of %s: %d}\n", DL -> name, DL -> size);
		return;
	}

	Elem *curr = DL -> head;
	while (curr != NULL) {
		if (curr == DL -> curr) printf("*[%s] ~~> ", curr -> data);
		else printf("[%s] ~~> ", curr -> data);
		curr = curr -> next;
	}
	printf("NULL {Size of %s: %d}\n", DL -> name, DL -> size);
}

/** 
 * prints all elem in Doubly linked list (reverse)
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayReversedDoublyLinkedList(DoublyLinkedList DL) {
	assert(DL != NULL);
	printf("Reversed %s: ", DL -> name);
	if (DL -> size == 0) {
		printf("is empty {Size of %s: %d}\n", DL -> name, DL -> size);
		return;
	}
	printf("NULL ~~> ");
	Elem *curr = DL -> tail;
	while (curr != DL -> head) {
		if (curr == DL -> curr) printf("*[%s] ~~> ", curr -> data);
		else printf("[%s] ~~> ", curr -> data);
		curr = curr -> prev;
	}
	if (curr == DL -> curr) printf("*[%s] {Size of %s: %d}\n", curr -> data, DL -> name, DL -> size);
	else printf("[%s] {Size of %s: %d}\n", curr -> data, DL -> name, DL -> size);
}

/** 
 * insert new elem before current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertBeforeToDoublyLinkedList(DoublyLinkedList DL, char *data) {
	assert(DL != NULL);
	printf("> Attempting to insert [%s] before current in %s\n", data, DL -> name);
	if (contains(DL, data)) {
		printf("%s already contains [%s]\n", DL -> name, data);
		return;
	}
	Elem *elem = newElem(data);
	if (isEmpty(DL)) {
		DL -> head = DL -> tail = DL -> curr = elem;
		printf("Inserted [%s] in %s\n", elem -> data, DL -> name);
		DL -> size ++;
		return;
	} 
	else if (DL -> curr == DL -> head) {
		elem -> next = DL -> head;
		DL -> head -> prev = elem;
		DL -> curr = DL -> head = elem;
	}
	else if (DL -> curr == DL -> tail) {
		DL -> tail -> prev -> next = elem;
		elem -> prev = DL -> tail -> prev;
		elem -> next = DL -> tail;
		DL -> curr = DL -> tail -> prev = elem;
	} 
	else {
		elem -> prev = DL -> curr -> prev;
		elem -> next = DL -> curr;
		DL -> curr -> prev -> next = elem;
		DL -> curr -> prev = elem;
		DL -> curr = elem; 
	}
	DL -> size ++;
	printf("Inserted [%s] before [%s] in %s\n", elem -> data, elem -> next -> data, DL -> name);
}

/** 
 * insert new elem after current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertAfterToDoublyLinkedList(DoublyLinkedList DL, char *data) {
	assert(DL != NULL);
	printf("> Attempting to insert [%s] before current in %s\n", data, DL -> name);
	if (contains(DL, data)) {
		printf("%s already contains [%s]\n", DL -> name, data);
		return;
	}
	Elem *elem = newElem(data);
	if (isEmpty(DL)) {
		DL -> head = DL -> tail = DL -> curr = elem;
		printf("Inserted [%s] in %s\n", elem -> data, DL -> name);
		DL -> size ++;
		return;
	} 
	else if (DL -> curr == DL -> head) {
		elem -> prev = DL -> head;
		DL -> head -> next = elem;
		DL -> curr = DL -> tail = elem;
	}
	else if (DL -> curr == DL -> tail) {
		DL -> tail -> next = elem;
		elem -> prev = DL -> tail;
		DL -> curr = DL -> tail = elem;
	} 
	else {
		elem -> prev = DL -> curr;
		elem -> next = DL -> curr -> next;
		DL -> curr -> next -> prev = elem;
		DL -> curr -> next = elem;
		DL -> curr = elem; 
	}
	DL -> size ++;
	printf("Inserted [%s] before [%s] in %s\n", elem -> data, elem -> prev -> data, DL -> name);
}

/** 
 * free memory for all elem and Doubly linked list 
 * Time Complexity : O(n) 
 *
 * @param list
 */
void freeDoublyLinkedList(DoublyLinkedList DL) {
	assert(DL != NULL);
	printf("> Attempting to free %s\n", DL -> name);
	char *name = DL -> name;

	if (DL -> size == 0) {
		free(DL);
		printf("Freed %s\n", name);
		return;
	}

	Elem *curr = DL -> head;
	while (curr != NULL) {
		Elem *temp = curr;
		curr = curr -> next;
		free(temp);
	}
	free(DL);
	printf("Freed %s\n", name);
}

/** 
 * remove current elem from Doubly linked list 
 * (remove elem if in list, new current will be elem after old current)
 * Time Complexity : O(1) 
 *
 * @param list
 */
void removeFromDoublyLinkedList(DoublyLinkedList DL) {
	assert(DL != NULL);
	if (DL -> curr != NULL) printf("> Attempting to remove [%s] from %s\n", DL -> curr -> data, DL -> name);
	if (isEmpty(DL)) {
		printf("> Attempting to remove... ");
		printf("%s is already empty!\n", DL -> name);
		return;
	}
	else if (DL -> size == 1) {
		Elem *temp = DL -> head;
		DL -> head = DL -> tail = DL -> curr = NULL;
		printf("Removed [%s] from %s, list is now empty!", temp -> data, DL -> name);
		free (temp);
	}
	else if (DL -> size == 2) {
		if (DL -> head == DL -> curr) {
			Elem *temp = DL -> head;
			DL -> tail -> prev = NULL;
			DL -> head = DL -> curr = DL -> tail;
			printf("Removed [%s] from %s, new current is [%s] ", temp -> data, DL -> name, DL -> curr -> data);
			free(temp);
		}
		else if (DL -> tail == DL -> curr){
			Elem *temp = DL -> tail;
			DL -> head -> next = NULL;
			DL -> tail = DL -> curr = DL -> head;
			printf("Removed [%s] from %s, new current is [%s] ", temp -> data, DL -> name, DL -> curr -> data);
			free(temp);
		}
	}
	else {
		if (DL -> head == DL -> curr) {
			Elem *temp = DL -> head;
			DL -> head = DL -> curr = temp -> next;
			DL -> head -> prev = DL -> curr -> prev = NULL;
			printf("Removed [%s] from %s, new current is [%s] ", temp -> data, DL -> name, DL -> curr -> data);
			free(temp);
		}
		else if (DL -> tail == DL -> curr){
			Elem *temp = DL -> tail;
			DL -> tail = DL -> curr = temp -> prev;
			DL -> tail -> next = DL -> curr -> next = NULL;
			printf("Removed [%s] from %s, new current is [%s] ", temp -> data, DL -> name, DL -> curr -> data);
			free(temp);
		}
		else {
			Elem *temp = DL -> curr;
			DL -> curr -> prev -> next = DL -> curr -> next;
			DL -> curr -> next -> prev = DL -> curr -> prev;
			DL -> curr = temp -> next;
			printf("Removed [%s] from %s, new current is [%s] ", temp -> data, DL -> name, DL -> curr -> data);
			free(temp);
		}
	}
	DL -> size --;
	printf("{Size of %s: %d}\n", DL -> name, DL -> size);
}

/**
 * move current ptr position
 * (recursive function)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param shift
 */
int moveCurrentPtr(DoublyLinkedList DL, int shift) {
	assert (DL != NULL);
	return moveCurrent(DL, shift);
}

/** 
 * Helper function - to create an elem node
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param data
 * @return ptr to Elem
 */
static Elem *newElem(char *data) {
	Elem *new = malloc(sizeof(Elem));
	assert(new != NULL);
	new -> data = strdup(data);
	new -> prev = NULL;
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
static bool contains(DoublyLinkedList DL, char *data) {
	Elem *curr = DL -> head;
	while (curr != NULL) {
		if (curr -> data == data) {
			return true;
		}
		curr = curr -> next;
	}
	return false;
}

/** 
 * Helper function - to check if list is empty
 * Time Complexity : O(1) 
 *
 * @param list
 * @return true if empty
 * @return false if not empty
 */
static bool isEmpty(DoublyLinkedList DL) {
	return (DL -> size == 0);
}

/**
 * Helper function - move current ptr position
 * Time Complexity : O(n) 
 *
 * @param list
 * @param shift
 */
static int moveCurrent(DoublyLinkedList DL, int shift) {
	if (DL -> curr == NULL) return 1;
	else if (shift > 0) {
		while (shift > 0 && DL -> curr -> next != NULL) {
			DL -> curr = DL -> curr -> next;
			shift --;
		}
	}
	else if (shift < 0) {
		while (shift < 0 && DL -> curr -> prev != NULL) {
			DL -> curr = DL -> curr -> prev;
			shift ++;
		}
	}
	return (DL -> curr == DL -> head || DL -> curr == DL -> tail) ? 1 : 0;
}
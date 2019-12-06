// Written by wickwickthedog, December 2019
#include <stdlib.h>
#include <stdio.h>
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

// creates a new empty singly linked list
SinglyLinkedList newSinglyLinkedList(char *name) {
	SinglyLinkedList l = malloc(sizeof(SinglyLinkedList));
	assert(l != NULL);
	l -> name = name;
	l -> size = 0;
	l -> head = NULL;
	l -> tail = NULL;
	return l;
}

void displaySinglyLinkedList(SinglyLinkedList SL) {
	assert(SL != NULL);
	printf("%s: ", SL -> name);
	if (SL -> size == 0) {
		printf("is empty\n");
		return;
	};

	Elem *curr = SL -> head;
	while (curr != NULL) {
		printf("[%d] ~~> ", curr -> data);
		curr = curr -> next;
	}
	printf(" NULL {Size of List: %d}\n", SL -> size);
}

static Elem *newElem(int data) {
	Elem *new = malloc(sizeof(Elem));
	assert(new != NULL);
	new -> data = data;
	new -> next = NULL;
	return new;
}

void appendToSinglyLinkedList(SinglyLinkedList SL, int data) {
	assert(SL != NULL);
	Elem *elem = newElem(data);
	if (SL -> size == 0) SL -> head = SL -> tail = elem;
	else if (SL -> size == 1) {
		SL -> head -> next = elem;
		SL -> tail = elem;
	}
	else {
		SL -> tail -> next = elem;
		SL -> tail = elem;
	};
	SL -> size ++;
	printf("Appended %d into %s\n", elem -> data, SL -> name);
}

void freeSinglyLinkedList(SinglyLinkedList SL) {
	assert(SL != NULL);
	if (SL -> size == 0) {
		free(SL);
		return;
	};

	Elem *curr = SL -> head;
	while (curr != NULL) {
		Elem *temp = curr;
		free(temp);
		curr = curr -> next;
	}
	free(SL);
	printf("Freed %s\n", SL -> name);
}

void removeFromSinglyLinkedList(SinglyLinkedList SL, int data) {
	assert(SL != NULL);
	Elem *curr = SL -> head;
	if (curr == SL -> head && curr -> data == data) {
		Elem *temp = curr;
		SL -> head -> next = curr -> next -> next;
		SL -> head = curr -> next;
		SL -> size --;
		free(temp);
		printf("Removed %d from %s\n", data, SL -> name);
		return;
	};

	while (curr != NULL) {
		if (curr -> next == SL -> tail && curr -> next -> data == data) {
			Elem *temp = SL -> tail;
			curr -> next = NULL;
			SL -> tail = curr;
			SL -> size --;
			free(temp);
			printf("Removed %d from %s\n", data, SL -> name);
			return;
		};
		if (curr -> data == data) {
			Elem *temp = curr;
			curr -> next = temp -> next;
			SL -> size --;
			free(temp);
			printf("Removed %d from %s\n", data, SL -> name);
			return;
		};
		curr = curr -> next;
	}
	printf("%d doesn't exist in %s\n", data, SL -> name);
}
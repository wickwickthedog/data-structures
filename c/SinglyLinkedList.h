// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

typedef struct singlyLinkedListRep *SinglyLinkedList;

// creates a new empty singly linked list
SinglyLinkedList newSinglyLinkedList();

// display list
void displaySinglyLinkedList(SinglyLinkedList);

// append elem
void appendToSinglyLinkedList(SinglyLinkedList, int);

// free singly linked list
void freeSinglyLinkedList(SinglyLinkedList);

// remove elem
void removeFromSinglyLinkedList(SinglyLinkedList, int);

#endif
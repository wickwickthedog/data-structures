// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef Doubly_LINKEDLIST_H
#define Doubly_LINKEDLIST_H

typedef struct doublyLinkedListRep *DoublyLinkedList;

/** 
 * creates an empty Doubly linked list
 *
 * @param name of the list
 * @return ptr to an empty Doubly linked list
 */
DoublyLinkedList newDoublyLinkedList(char *name);

/** 
 * prints all elem in Doubly linked list
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayDoublyLinkedList(DoublyLinkedList DL);

/** 
 * prints all elem in Doubly linked list (reverse)
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayReversedDoublyLinkedList(DoublyLinkedList DL);

/** 
 * insert new elem before current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertBeforeToDoublyLinkedList(DoublyLinkedList DL, char *data);

/** 
 * insert new elem after current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertAfterToDoublyLinkedList(DoublyLinkedList DL, char *data);

/** 
 * free memory for all elem and Doubly linked list 
 * Time Complexity : O(n) 
 *
 * @param list
 */
void freeDoublyLinkedList(DoublyLinkedList DL);

/** 
 * remove elem from Doubly linked list 
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void removeFromDoublyLinkedList(DoublyLinkedList DL);

/**
 * move current ptr position
 * (recursive function)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param shift
 */
int moveCurrentPtr(DoublyLinkedList DL, int shift);

#endif
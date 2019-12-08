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
DoublyLinkedList newDoublyLinkedList(char *);

/** 
 * prints all elem in Doubly linked list
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayDoublyLinkedList(DoublyLinkedList);

/** 
 * prints all elem in Doubly linked list (reverse)
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displayReversedDoublyLinkedList(DoublyLinkedList);

/** 
 * insert new elem before current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertBeforeToDoublyLinkedList(DoublyLinkedList, char *);

/** 
 * insert new elem after current node into Doubly linked list 
 * Time Complexity : O(1) but since check duplicates O(n)
 *
 * @param list
 * @param data
 */
void insertAfterToDoublyLinkedList(DoublyLinkedList, char *);

/** 
 * free memory for all elem and Doubly linked list 
 * Time Complexity : O(n) 
 *
 * @param list
 */
void freeDoublyLinkedList(DoublyLinkedList);

/** 
 * remove elem from Doubly linked list 
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void removeFromDoublyLinkedList(DoublyLinkedList);

/**
 * move current ptr position
 * (recursive function)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param shift
 */
int moveCurrentPtr(DoublyLinkedList, int);

#endif
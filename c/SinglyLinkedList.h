// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

typedef struct singlyLinkedListRep *SinglyLinkedList;

/** 
 * creates an empty singly linked list
 *
 * @param name of the list
 * @return ptr to an empty singly linked list
 */
SinglyLinkedList newSinglyLinkedList(char *name);

/** 
 * prints all elem in singly linked list
 * Time Complexity : O(n) 
 *
 * @param list
 */
void displaySinglyLinkedList(SinglyLinkedList SL);

/** 
 * append new elem into singly linked list 
 * (insert to the end of the list if not in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void appendToSinglyLinkedList(SinglyLinkedList SL, int data);

/** 
 * free memory for all elem and singly linked list 
 * Time Complexity : O(n) 
 *
 * @param list
 */
void freeSinglyLinkedList(SinglyLinkedList SL);

/** 
 * remove elem from singly linked list 
 * (remove elem if in list)
 * Time Complexity : O(n) 
 *
 * @param list
 * @param data
 */
void removeFromSinglyLinkedList(SinglyLinkedList SL, int data);

#endif
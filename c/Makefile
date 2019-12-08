CC=gcc
CFLAGS=-Wall -Werror -g
BINS=SinglyLinkedList DoublyLinkedList

all : $(BINS)

SinglyLinkedList : testSinglyLinkedList.o
testSinglyLinkedList.o : testSinglyLinkedList.c SinglyLinkedList.h

DoublyLinkedList : testDoublyLinkedList.o
testDoublyLinkedList.o : testDoublyLinkedList.c DoublyLinkedList.h

clean : 
	rm -f $(BINS) *.o
	rm -rf *.dSYM
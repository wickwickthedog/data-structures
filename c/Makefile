CC=gcc
CFLAGS=-Wall -Werror -g
BINS=SinglyLinkedList

all : $(BINS)

SinglyLinkedList : testSinglyLinkedList.o
testSinglyLinkedList.o : testSinglyLinkedList.c SinglyLinkedList.h

clean : 
	rm -f $(BINS) *.o
	rm -rf *.dSYM
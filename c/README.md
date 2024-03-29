
# C
## Quick Start
To compile and create object file(s),
```
> make
```
To see the object file(s) in current dir,
```
> ls
```
To run the object file, (e.g SinglyLinkedList),
```
> ./SinglyLinkedList
```
To remove object file(s),
```
> make clean
```
## NOTE:
If you make any changes to the code, you will need to recompile,
```
> make
```
then run the object file, (e.g SinglyLinkedList),
```
> ./SinglyLinkedList
```
For now, 
1. ./SinglyLinkedList
2. ./DoublyLinkedList

**You'll get seg fault for displaying list after free for older gcc version** 
## Singly Linked List
**Access:** Time <sub>complexity</sub>: O(n)

**Search:** Time <sub>complexity</sub>: O(n)

**Insertion:** Time <sub>complexity</sub>: not O(1) but O(n) because check duplicates elem in list

**Deletion:** Time <sub>complexity</sub>: not O(1) but O(n) because delete specific elem in list

Space <sub>complexity</sub>: O(n)

## Doubly Linked List
**Access:** Time <sub>complexity</sub>: O(n)

**Search:** Time <sub>complexity</sub>: O(n)

**Insertion:** Time <sub>complexity</sub>: not O(1) but O(n) because check duplicates elem in list

**Deletion:** Time <sub>complexity</sub>: O(1)

Space <sub>complexity</sub>: O(n)

## Adjacency List Graph
**Access:** Time <sub>complexity</sub>: O(|V| + |E|)

**Search:** Time <sub>complexity</sub>: O(|V| + |E|)

**Insertion:** Time <sub>complexity</sub>: not O(|V|) but O(|V| + |E|) since i didn't keep track of last elem in list

**Deletion:** Time <sub>complexity</sub>: not O(|V|) but O(|V| + |E|) because delete specific elem in list

Space <sub>complexity</sub>: O(|V| + |E|)

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
**You'll get seg fault for displaying list after free for older gcc version** 
## Singly Linked List
**Access:** Time <sub>complexity</sub>: O(n)
**Search:** Time <sub>complexity</sub>: O(n)
**Insertion:** Time <sub>complexity</sub>: not O(1) but O(n) because check duplicates elem in list
**Deletion:** Time <sub>complexity</sub>: not O(1) but O(n) because delete specific elem in list
Space <sub>complexity</sub>: O(n)


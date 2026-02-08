# Doubly Linked List 

To implement a Doubly Linked List using structures in C and perform insertion after a given node and deletion of a node.
---

## (a) Data Structure Definition
A doubly linked list node contains three parts:
- `data` : Stores the value
- `prev` : Pointer to the previous node
- `next` : Pointer to the next node

```c
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```

## (b) Functions Implemented

1. **insertAfter**: Inserts a new node after a given node in the doubly linked list.
    - Allocate memory for the new node
    - Adjust `next` and `prev` pointers properly

2. **deleteNode()**:Deletes a given node from the doubly linked list.
    - Update head if required
    - Fix links of adjacent nodes
    - Free the memory of deleted node

3. **display()**: displays all the elements of doulbly linked list from start to end

## (c) Overview of `Main ()`

- Creates two initial nodes
- Displays the original list
- Inserts a node after the first node
- Deletes a specified node
- Displays the updated list after each operation

## (d) Sample output

- Original Doubly Linked List:
10 <-> 20 <-> NULL

- After inserting 15 after 10:
10 <-> 15 <-> 20 <-> NULL

- After deleting 20:
10 <-> 15 <-> NULL

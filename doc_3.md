
# Program 3 – Implementing the reverse traversal algorithm in the the linked list

## 1. Data Structure Definition
This program uses a 'singly linked list' data structure defined by the following:

- Node Structure (`Node`) 
  - Contains an integer value `value`.  
  - Contains a pointer `next` pointing to the next node in the list (or `NULL` if it's the last node).
- The linked list is managed through a pointer `head` that points to the first node.

## 2. Description of Functions Implemented

1. `Node* makeNode(int val)` 
   - Dynamically allocates memory for a new node.  
   - Initializes the node’s `value` with `val`.  
   - Sets the node’s `next` pointer to `NULL`.  
   - Returns a pointer to the newly created node.

2. `void addEnd(Node** head, int val)`
   - Adds a new node with value `val` to the **end** of the linked list.  
   - If the list is empty (`*head == NULL`), sets the new node as the head.  
   - Otherwise, traverses to the last node and links the new node after it.

3. `void printReverse(Node* node)` 
   - Recursively prints the linked list in **reverse order**.  
   - Base case: returns if the current node is `NULL`.  
   - Recursively calls itself on the `next` node, then prints the current node’s value after returning from recursion.

## 3. Organization of `main()`

- Initializes an empty linked list by setting `list` to `NULL`.  
- Adds nodes with values `10, 20, 30, 40, 50` to the end of the list using `addEnd()`.  
- Prints the linked list in reverse order by calling `printReverse()`.  
- Frees all allocated nodes to avoid memory leaks by traversing and freeing each node one by one.  
- Returns 0 to indicate successful execution.


## 4. Sample Output
 50 40 30 20 10

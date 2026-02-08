#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAfter(struct Node *prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData; //Store the value newData into the new node’s data
    newNode->next = prevNode->next; //The new node should point to whatever comes after prevNode
    newNode->prev = prevNode; //The new node’s prev should point back to prevNode

    if (prevNode->next != NULL)

        prevNode->next->prev = newNode; /* This fixes the backward link of the next node.
                            If prevNode->next is not NULL (means there is a node after prevNode):
                            we set that next node’s prev pointer to the new node */
        prevNode->next = newNode;
}

void deleteNode(struct Node **head, struct Node *delNode)/*head change huncha delete garepaxi tesaile
                    head modify garna lai **head gareko */
{
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL) /*delNode ko next exist garcha bhane delete garepaxi tesko prev,
                    next ko prev huncha*/
        delNode->next->prev = delNode->prev; /* so yesma chai, delNode ko next cha tesko prev chai aba 
                    delNode ko prev huncha*/

    if (delNode->prev != NULL) 
        delNode->prev->next = delNode->next;

    free(delNode);// releases the memory of deleted node 
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 10;
    first->prev = NULL;
    first->next = NULL;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 20;
    second->prev = first;
    second->next = NULL;

    first->next = second;
    head = first;

    printf("Original Doubly Linked List:\n");
    display(head);

    insertAfter(first, 15);
    printf("\nAfter inserting 15 after 10:\n");
    display(head);

    deleteNode(&head, second);
    printf("\nAfter deleting 20:\n");
    display(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* makeNode(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = val;
    new->next = NULL;
    return new;
}

void addEnd(Node** head, int val) {
    Node* new = makeNode(val);
    
    if (*head == NULL) {
        *head = new;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

void printReverse(Node* node) {
    if (node == NULL) return;
    printReverse(node->next);
    printf("%d ", node->value);
}

int main() {
    Node* list = NULL;
    addEnd(&list, 10);
    addEnd(&list, 20);
    addEnd(&list, 30);
    addEnd(&list, 40);
    addEnd(&list, 50);
    
    printf("List backwards: ");
    printReverse(list);
    printf("\n");
    
    Node* temp;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    
    return 0;
}

#include "linkedlist.h"


void AddNode(struct Node *node, char data[255]) {
    
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    node->next = newNode;

}


void PrintList(struct Node *node) {

    struct Node *currentNode = node;

    while (currentNode != NULL) {

        printf("%s\n", currentNode->data);
        currentNode = currentNode->next;

    }

}


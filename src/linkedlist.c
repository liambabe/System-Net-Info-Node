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

void CleanList(struct Node *node) {

	struct Node *headNode = node;

	if (headNode->next == NULL) {
		return; // already clean
	} else {

		struct Node *currentNode = headNode->next;
		headNode->next = NULL;

		while (currentNode->next != NULL) {
			//make temp variable of current and switch to next
			struct Node *tmp = currentNode; 
			currentNode = currentNode->next; 
			//cleaning
			tmp->next = NULL; 
			free(tmp);
		}
		free(currentNode);
	}
}
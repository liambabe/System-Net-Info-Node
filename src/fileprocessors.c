#include "fileprocessors.h"


char* ProcessMemoryFile(struct Node* n, char* data)
{
	struct Node *currentNode = n->next;

	while (currentNode != NULL) {

		char temp[255];
		char *classifier;

		strcpy(temp, currentNode->data);
		char *token = strtok(temp, " ");
		classifier = token;
		token = strtok (NULL, " ");


		if (strcmp(classifier, "MemTotal:") || strcmp(classifier, "MemAvailable:")) {
			strcat(data, token);
			strcat(data, ",");
		}

		currentNode = currentNode->next;

	}

}
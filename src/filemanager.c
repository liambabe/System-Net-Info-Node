#include "filemanager.h"


void OpenFiles() 
{

	char *memoryFilePath = CombineFilePath(strdup(process), "meminfo");
	memInfo = fopen(memoryFilePath, "r");

	char *cpuFilePath = CombineFilePath(strdup(process), "stat");
	cpuInfo = fopen(cpuFilePath, "r");
	
	if (!memInfo || !cpuInfo) {
		printf("Failed to open a file\n");
	}

	free(memoryFilePath);
	free(cpuFilePath);
}


static char* CombineFilePath(char *folder, char *filename)
{
	//Combine file path and file name

	char *filePath;
	filePath = malloc(strlen(folder)+1+strlen(filename));
	strcpy(filePath, folder); 
	strcat(filePath, filename); 

	return filePath;
}


void CloseFiles() 
{
	fclose(memInfo);
	fclose(cpuInfo);
}


void ReadFile(FILE **filestream, struct Node* n, int lines) 
{

	char buffer[255];
	struct Node *currentNode = n;

	for (int i = 0; i < lines; i++) {

		fgets(buffer, 255, *filestream);
		AddNode(currentNode, buffer);

		currentNode = currentNode->next;

	}
}
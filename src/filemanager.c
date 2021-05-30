#include "filemanager.h"


const char process[7] = "/proc/\0";

FILE *memInfo;
struct Node *memHead = NULL;

FILE *cpuInfo;
struct Node *cpuHead = NULL;


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

void initDataLists ()
{ 
	memHead = (struct Node*) malloc(sizeof(struct Node));
	strcpy(memHead->data, "Memory List");

	cpuHead = (struct Node*) malloc(sizeof(struct Node));
	strcpy(cpuHead->data, "CPU List");
}

char* ProcessData(char* data) {

	OpenFiles();

	ReadFile(&memInfo, memHead, 3);
	ReadFile(&cpuInfo, cpuHead, 7);

	ProcessMemoryFile(memHead, data);

	CloseFiles();

	CleanList(memHead);
	CleanList(cpuHead);

	return data;
}
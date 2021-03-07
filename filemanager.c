#include "filemanager.h"


void OpenFiles() 
{

  char *memoryFilePath = CombineFilePath(strdup(process), "meminfo");
  memInfo = fopen(memoryFilePath, "r");
  
  if (!memInfo) {
    printf("Failed to open memory file\n");
  }

  free(memoryFilePath);
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

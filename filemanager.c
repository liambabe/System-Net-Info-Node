#include "filemanager.h"
#include "Main.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void OpenFiles() 
{

  memInfo = fopen(CombineFilePath(strdup(process), "meminfo"), "r");
  
  if (!memInfo) {
    printf("Failed to open memory file\n");
  }

}

static char* CombineFilePath(char *folder, char *filename)
{
  //Combine file path and file name

  char* filePath;
  filePath = malloc(strlen(folder)+1+strlen(filename));
  strcpy(filePath, folder); 
  strcat(filePath, filename); 

  return filePath;
}


void CloseFiles() 
{
  fclose(memInfo);
}


void ReadFile(FILE **filestream, char buffer[]) {

  fscanf(*filestream, "%s", buffer);

}

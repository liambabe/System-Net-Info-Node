#include "filemanager.h"

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


void ReadFile(FILE **filestream, char buffer[]) 
{
  int i = 0;  

  while (fgets(buffer, 255, *filestream)) {
    printf("%s", buffer);
  }

}

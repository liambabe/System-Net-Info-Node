#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// file control functions
void OpenFiles();
void CloseFiles();

// input/output functions
void ReadFile(FILE **filestream, char buffer[]);

static char* CombineFilePath(char *folder, char *filename);

#endif

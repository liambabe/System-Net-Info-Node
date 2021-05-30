#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Main.h"
#include "linkedlist.h"

char* ProcessData(char* data);

// file control functions
void OpenFiles();
void CloseFiles();

// input/output functions
void ReadFile(FILE **filestream, struct Node* n, int lines);

// utility functions
static char* CombineFilePath(char *folder, char *filename);
void initDataLists ();

//process directory
extern const char process[7];

//file pointers
extern FILE *memInfo;
extern FILE *cpuInfo;

#endif
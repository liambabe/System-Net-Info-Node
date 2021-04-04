#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>

#include "filemanager.h"
#include "cpufileprocess.h"
#include "linkedlist.h"

extern const char process[7];

extern FILE *memInfo;
extern FILE *cpuInfo;

void initDataLists ();

#endif

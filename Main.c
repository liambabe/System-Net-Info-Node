#include "Main.h"


const char process[7] = "/proc/\0";

FILE *memInfo;
struct Node *memHead = NULL;

FILE *cpuInfo;
struct Node *cpuHead = NULL;

int main (int argc, char *argv[])
{
  initDataLists();

  OpenFiles();

  ReadFile(&memInfo, memHead, 5);
  ReadFile(&cpuInfo, cpuHead, 7);

  PrintList(memHead);
  PrintList(cpuHead);

  CloseFiles();
}


void initDataLists ()
{ 
  memHead = (struct Node*) malloc(sizeof(struct Node));
  strcpy(memHead->data, "Memory List");

  cpuHead = (struct Node*) malloc(sizeof(struct Node));
  strcpy(cpuHead->data, "CPU List");
}

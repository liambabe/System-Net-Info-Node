#include "Main.h"


const char process[6] = "/proc/";

FILE *memInfo;
struct Node *memHead = NULL;

int main (int argc, char *argv[])
{
  memHead = (struct Node*) malloc(sizeof(struct Node));
  strcpy(memHead->data, "Memory List");

  OpenFiles();

  ReadFile(&memInfo, memHead, 5);
  PrintList(memHead);

  CloseFiles();
}


#include "Main.h"

const char process[6] = "/proc/";

FILE *memInfo;
char memBuffer[255] = "";

int main (int argc, char *argv[])
{
  OpenFiles();

  ReadFile(&memInfo, memBuffer);

  printf("%s\n", memBuffer);

  ReadFile(&memInfo, memBuffer);

  printf("%s\n", memBuffer);

  CloseFiles();

}


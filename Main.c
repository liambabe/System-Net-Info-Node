#include "Main.h"

const char process[6] = "/proc/";

FILE *memInfo;
char memBuffer[255] = "";

int main (int argc, char *argv[])
{
  OpenFiles();

  ReadFile(&memInfo, memBuffer);

  CloseFiles();
}


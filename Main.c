#include "Main.h"

const char process[6] = "/proc/";

FILE *memInfo;

int main (int argc, char *argv[])
{
  OpenFiles();

  //ReadFile(&memInfo, memBuffer);

  CloseFiles();
}


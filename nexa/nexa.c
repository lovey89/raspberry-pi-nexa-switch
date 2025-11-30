#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "nexalib/nexalib.h"
#include "constants.h"

/* PRIVATE FUNCTION DECLARATIONS */
void printUsage();

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printUsage();
    return 3;
  }
  else
  {
    Nexa__setup();

    bool activate;
    if (strcmp(argv[2], "on") == 0)
    {
      activate = true;
    }
    else if (strcmp(argv[2], "off") == 0)
    {
      activate = false;
    }
    else
    {
      printf("Last argument should be 'on' or 'off'.\n");
      return 1;
    }

    if (strcmp(argv[1], "group") == 0) // Send command to whole group
    {
      Nexa__sendCode(GROUP_CODE, true, activate, 0b0000);
    }
    //else if (strcmp(argv[1], "dev") == 0) //Alternera bitarna vid testning i audacity
    //{
    //}
    else {
      char* end;
      const long i = strtol(argv[1], &end, 10);

      if (*end == '\0' && i >= 1 && i <= 16) {
        Nexa__sendCode(GROUP_CODE, false, activate, i - 1);
      }
      else
      {
        printUsage();
        return 2;
      }
    }
    return 0;
  }
}

void printUsage()
{
  printf("usage:\n"
         "  ./nexa [1-16] [on|off]   : turn on/off corresponding channel\n"
         "  ./nexa group  [on|off]   : turn on/off all channels\n");
}

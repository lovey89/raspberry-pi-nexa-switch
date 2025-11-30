#ifndef NEXA_H
#define NEXA_H

#include <stdlib.h>
#include <stdbool.h>

void Nexa__setup();

void Nexa__sendCode(int32_t groupCode, bool groupCommand, bool activate, char deviceCode, char sendTimes);

#endif // NEXA_H

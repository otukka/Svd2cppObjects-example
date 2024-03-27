

#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdarg.h>
#include <stdint.h>

#define DEBUG_BUFFER_LEN 1024

void debugSerialInit(void);
void serialPrint(const char* a_format, ...);

#endif /* DEBUG_H_ */

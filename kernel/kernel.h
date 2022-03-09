#ifndef KERNEL_H
#define KERNEL_H

#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../libc/function.h"
#include "../drivers/serial.h"
#include "../apps/apps.h"

void user_input(char *input);
void print_prompt();

#endif

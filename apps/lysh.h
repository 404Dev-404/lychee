#include "../drivers/screen.h"
#include "../drivers/serial.h"
#include "../cpu/types.h"
#include "../libc/mem.h"
#include "../libc/string.h"
#include "../cpu/isr.h"

void print_prompt();
void error(char *cmd);
void page();
void fizzbuzz(int mode);
void info();
void init_kernel();
void cpu_stop();
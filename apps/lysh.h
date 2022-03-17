#include "../drivers/screen.h"
#include "../drivers/serial.h"
#include "../cpu/types.h"
#include "../libc/mem.h"
#include "../libc/string.h"
#include "../cpu/isr.h"
#include "../drivers/parallel.h"

void die(char error);
void print_prompt();
void error(char *cmd);
void page();
void fizzbuzz(int mode);
void info();
void init_kernel();
void cpu_stop();
void parallel_test();
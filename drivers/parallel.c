#include "parallel.h"
#include "../cpu/ports.h"
#include "../libc/string.h"

void parallel_write(unsigned char a) {
    unsigned char control;
    while (!port_byte_in(0x379) & 0x80) {};
    port_byte_out(0x378, a);
    control = port_byte_in(0x37a);
    port_byte_out(0x37a, control | 1);
    port_byte_out(0x37a, control);
    while (!port_byte_in(0x379) & 0x80) {};
}

void pprint(char data[]) {
    int size = strlen(data);
    for (int i = 0; i < size; i++)
        parallel_write(data[i]);
}
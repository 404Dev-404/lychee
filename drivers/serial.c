#include "serial.h"
#include "parallel.h"
#include "../libc/string.h"
#define PORT 0x3F8

int init_serial() {
    port_byte_out(PORT + 1, 0x00);
    port_byte_out(PORT + 3, 0x80);
    port_byte_out(PORT + 0, 0x03);
    port_byte_out(PORT + 1, 0x00);
    port_byte_out(PORT + 3, 0x03);
    port_byte_out(PORT + 2, 0xC7);
    port_byte_out(PORT + 4, 0x0B);
    port_byte_out(PORT + 4, 0x1E);
    port_byte_out(PORT + 0, 0xAE);

    if (port_byte_in(PORT + 0) != 0xAE) {
        return 1;
    }

    port_byte_out(PORT + 4, 0x0F);
    return 0;
}

int serial_received() {
    return port_byte_in(PORT + 5) & 1;
}

char read_serial() {
    while (serial_received() == 0);
    return port_byte_in(PORT);
}

int is_transmit_empty() {
    return port_byte_in(PORT + 5) & 0x20;
}

void write_serial(char a) {
    while (is_transmit_empty() == 0);
    port_byte_out(PORT, a);
}

void sprint(char data[]) {
    int size = strlen(data);
    for (int i = 0; i < size; i++)
        write_serial(data[i]);
}

void kernel_log(char data[]) {
    sprint("-=[LOG]=- ");
    sprint(data);
    sprint("\r\n");
    pprint("-=[LOG]=- ");
    pprint(data);
    pprint("\r\n");
    kcolor_change(0x0b);
    kprint("-=[LOG]=- ");
    kcolor_change(0x0f);
    kprint(data);
    kprint("\n");
}
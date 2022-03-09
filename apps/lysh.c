#include "lysh.h"

void print_prompt() {
    kprint("\nlysh> ");
}

void error(char *cmd) {
    kprint("lysh error: ");
    kprint(cmd);
    kprint(" is not a command.\n");
    print_prompt();
}

void page() {
        sprint("PAGE");
        u32 phys_addr;
        u32 page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        sprint(", PageAddress: ");
        sprint(page_str);
        kprint(", physical address: ");
        sprint(", PhysicalAddress: ");
        sprint(phys_str);
        sprint("\r\n");
        kprint(phys_str);
        print_prompt();
}

void fizzbuzz(int mode) {
    if (mode == 0) {
        int i;
        char i_str[4];
        for (i = 1; i <= 100; i++) {
            if (((i % 3) || (i % 5)) == 0) {
                kprint("FizzBuzz\n");
            } else if ((i % 3) == 0) {
                kprint("Fizz\n");
            } else if ((i % 5) == 0) {
                kprint("Buzz\n");
            } else {
                int_to_ascii(i, i_str);
                kprint(i_str);
                kprint("\n");
            }
        }
        print_prompt();
    } else {
        int i;
        char i_str[4];
        for (i = 1; i <= 100; i++) {
            if (((i % 3) || (i % 5)) == 0) {
                sprint("FizzBuzz\r\n");
            } else if ((i % 3) == 0) {
                sprint("Fizz\r\n");
            } else if ((i % 5) == 0) {
                sprint("Buzz\r\n");
            } else {
                int_to_ascii(i, i_str);
                sprint(i_str);
                sprint("\r\n");
            }
        }
        print_prompt();
    }
}

void info() {
    char *build_date = __TIMESTAMP__;
    kprint("Lychee:2.0\nBuild Date: ");
    kprint(build_date);
}

void init_kernel() {
    install();
    if (init_serial() != 0) {
        kprint("Serial Not Initialized.\n");
    }
    clear_screen();
    kprint("Welcome to LycheeOS!\n");
    print_prompt();
}

void cpu_stop() {
    sprint("CPU_STOP\r\n");
    kprint("Stopping the CPU. Bye!\n");
    asm volatile("hlt");
}
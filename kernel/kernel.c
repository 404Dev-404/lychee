#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../libc/function.h"
#include "../libc/sort.h"

int test[] = {27, 758, 145, 24, 145, 64, 256, 32};
int test_size = sizeof(test)/sizeof(test[0]);

void info() {
    char *build_date = __TIMESTAMP__;
    kprint("LycheeOS v1.2.0\nBuild Date: ");
    kprint(build_date);
}

void print_prompt() {
    kprint("\nlysh> ");
}

void kernel_main() {
    install();
    clear_screen();
    kprint("Welcome to LycheeOS!\n");
    print_prompt();
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "HELP") == 0) {
        kprint("LySH Help:\nTo quit Lychee type \"END\".\nTo get info type \"INFO\".\nTo request a kmalloc() type \"PAGE\".\n");
        print_prompt();
    } else if (strcmp(input, "INFO") == 0) {
        print_prompt();
    } else if (strcmp(input, "PAGE") == 0) {
        u32 phys_addr;
        u32 page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        print_prompt();
    } else if (strcmp(input, "CLS") == 0) {
        clear_screen();
        print_prompt();
    } else if (strcmp(input, "HEX") == 0) {
        int t = 0xCA11CE11; // call cell
        // it rhymed i think
        char tstr[32] = "";
        hex_to_ascii(t, tstr);
        kprint(tstr);
        kprint("\n");
        print_prompt();
    } else {
        kprint("lysh error: ");
        kprint(input);
        kprint(" is not a command.\n");
        print_prompt();
    }
}

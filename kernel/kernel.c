#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"

void main() {
    isr_install();
    irq_install();
    clear_screen();

    kprint("Welcome to LycheeOS!\n");
    kprint("> ");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "HELP") == 0) {
        kprint("LySH Help:\nTo quit Lychee type \"END\".\n");
        kprint("> ");
    } else {
        kprint("lysh error: ");
        kprint(input);
        kprint(" is not a command.");
        kprint("\n> ");
    }
}

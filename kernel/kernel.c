#include "kernel.h"
#include "../cpu/timer.h"
char* help = "LySH Help:\n"
             "To quit Lychee type \"END\".\n"
             "To clear screen type \"CLS\".\n"
             "To get info type \"INFO\".\n"
             "To request a kmalloc() type \"PAGE\".\n"
             "To run FizzBuzz VGA Test type \"FIZZBUZZ\".\n"
             "To verify serial functionality/run FizzBuzz on serial console type \"SERIALTEST\"."
             "To get the ticks counted by the PIT type \"TICKS\".\n"
             "To cause a kernel crash type \"DIVBYZERO\" or press Esc.\n"
             "To test parallel type \"PARALLEL\".\n";

void main() {
    init_kernel();
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        cpu_stop();
    } else if (strcmp(input, "HELP") == 0) {
        kprint(help);
        print_prompt();
    } else if (strcmp(input, "PAGE") == 0) {
        page();
    } else if (strcmp(input, "CLS") == 0) {
        clear_screen();
        print_prompt();
    } else if (strcmp(input, "FIZZBUZZ") == 0) {
        fizzbuzz(0);
    } else if (strcmp(input, "SERIALTEST") == 0) {
        fizzbuzz(1);
    } else if (strcmp(input, "PARALLEL") == 0) {
        parallel_test();
        print_prompt();
    } else if (strcmp(input, "TICKS") == 0) {
        get_ticks();
        print_prompt();
    } else if (strcmp(input, "DIVBYZERO") == 0) {
        // i have no idea how this works but it does
        int i = 1 / (1 - 1);
        print_prompt();
    } else {
        error(input);
    }
}

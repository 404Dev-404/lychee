#include "kernel.h"
#include "../cpu/timer.h"
char* help = "LySH Help:\nTo quit Lychee type \"END\".\nTo get info type \"INFO\".\nTo request a kmalloc() type \"PAGE\".\nTo run FizzBuzz VGA Test type \"FIZZBUZZ\".\nTo verify serial functionality/run FizzBuzz on serial console type \"SERIALTEST\".";

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
    } else {
        error(input);
    }
}

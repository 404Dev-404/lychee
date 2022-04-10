/*
header: 0x71 0xCE 0xEE 0xEE
(liceeeee) (can't write h in hexadecimal)
*/
int initrd[] = {0x71, 0xCE, 0xEE, 0xEE};

#include "initrd.h"
#include "../drivers/screen.h"

int error_code = 0;

int read_initrd() {
    int header[4] = {0x71, 0xCE, 0xEE, 0xEE};
    for (int i = 0; i < 3; i++) {
        if (header[i] != initrd[i]) {
            error_code = -1;
            kprint("initrd corrupt or invalid\n");
            return error_code;
        } 
    }
    return 0;
}
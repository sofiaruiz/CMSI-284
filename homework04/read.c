#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

int returnCode = 0;

static bool legal(__int32_t codepoint) { //tells when a codepoint is legal
    return codepoint <= 0x0010FFFF
        && (codepoint < 0x0000FDD0 || codepoint > 0x0000FDEF)
        && (codepoint & 0x0000FFFE) != 0x0000FFFE;
}

void to_utf_8(__int32_t c) {
    if (!legal(c)) {
        returnCode = 1;
        putchar(0xEF);
        putchar(0xBF);
        putchar(0xBD);
    } else if (c <= 0x7F) {
        putchar(c);
    } else if (c <= 0x7FF) {
        putchar(0xC0 | c>>6);
        putchar(0x80 | (c & 0x3F));
    } else if (c <= 0xFFFF) {
        putchar(0xE0 | c>>12);
        putchar(0x80 | (c>>6 & 0x3F));
        putchar(0x80 | (c & 0x3F));
    } else {
        putchar(0xF0 | c>>18);
        putchar(0x80 | (c>>12 & 0x3F));
        putchar(0x80 | (c>>6  & 0x3F));
        putchar(0x80 | (c & 0x3F));
    }
}

int main(){
    const int BLOCK_SIZE = 500;

    unit32_t buffer[BLOCK_SIZE];

    while (true) {
        int size = fread(buffer, 4, BLOCK_SIZE, stdin); //returns the amount of bytes
        if (size == 0) {
            break;
        }
        for (int i = 0; i < size; i++) {
            to_utf_8(buffer[i]);
        }
    }
    return returnCode;
}

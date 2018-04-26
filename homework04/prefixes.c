#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_prefix(char* s, int size) {
    int c = 0;
    for (int i = 0; i < size; i++) {
        putchar(s[i]);
    }
    putchar(c);
}

static void print_prefixes(char* s) {
    for (int i = 0; i <= strlen(s); i++) {
      print_prefix(s, i);
    }
}

static void backwards_print_prefixes(char* s) {
    for (int i = strlen(s); i > 0; i--) {
        print_prefix(s, i);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Need two command line arguments!\n");
        return 1;
    }
    printf("\"");
    print_prefixes(argv[1]);
    backwards_print_prefixes(argv[2]);
    printf("\"\n");
    return 0;
}

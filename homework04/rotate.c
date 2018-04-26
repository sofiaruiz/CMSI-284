#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

static char* rotate(char* s, int k) {
    char* answer = malloc(strlen(s) + 1);
    for (int i = 0; i < strlen(s); i++) {
        answer[i] = s[(i+k)%(strlen((s)))];
    }
    return answer;
}

int main(int argc, char** argv) {
    assert(strcmp(rotate("doghouse", 3), "housedog") == 0);
    assert(strcmp(rotate("doghouse", 7), "edoghous") == 0);
    assert(strcmp(rotate("doghouse", 1), "oghoused") == 0);
    assert(strcmp(rotate("doghouse", 9), "oghoused") == 0);
    assert(strcmp(rotate("doghouse", 1), "oghoused") == 0);
    puts("Everything passed\n");
    return 0;
}

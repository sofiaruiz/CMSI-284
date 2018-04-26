#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* KEY_NAMES[] = {"A", "A#","B","C","C#","D","D#","E","F","F#","G","G#"};
const double NUMBER_OF_NOTES = 12;

int MAJOR_STEPS[6] = {2,2,1,2,2,2};
int MINOR_STEPS[6] = {2,1,2,2,1,2};
const double NUMBER_OF_STEPS = 6;

static int key_index(char * s){
    int index = 0;
    for (int i = 0; i < NUMBER_OF_NOTES; i++) {
        if (strcmp(s, KEY_NAMES[i]) == 0) {
            index = i;
            return index;
        }
    }
    printf("No such key\n");
    exit(2);
}

static void print_scale(int note_index, char* type, int* steps) {
    printf("%s %s: %s", KEY_NAMES[note_index], type, KEY_NAMES[note_index]);
    int offset = 0;
    for( int step = 0; step < NUMBER_OF_STEPS; step ++) {
        offset += steps[step];
        printf("%s", KEY_NAMES[((int)note_index + (int)offset) % (int)NUMBER_OF_NOTES]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("This program requires exactly one command line argument\n");
        return 1;
    }

    print_scale(key_index(argv[1]), "major", MAJOR_STEPS);
    print_scale(key_index(argv[1]), "minor", MINOR_STEPS);
}

#include <stdio.h>
#include <string.h>
#include <math.h>

const double NUMBER_OF_KEYS = 88;
char* keys[] = {"A", "A#","B","C","C#","D","D#","E","F","F#","G","G#"};
const double INITIAL_FREQUENCY = 27.5;

int main() {
    for (int i = 0; i < NUMBER_OF_KEYS; i++) {
        char* key_name = keys[i % 12];
        double frequencey = INITIAL_FREQUENCY * pow(2.0, i / 12.0);
        printf("%s\t%15.4f\n", key_name, frequencey);
    }
    return 0;
}

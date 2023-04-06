#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pig.c"

int main() {
    char words[][100] = {"happy", "duck", "glove", "evil", "eight", "yowler", 
    "crystal"};

    int num_words = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < num_words; i++) {
        printf("%s => ", words[i]);
        printf("%s\n", pig(words[i]));
    }
    return 0;
}
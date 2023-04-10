#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "riffle.h"


void riffle_once(void *L, int len, int size, void *work) {    
    // Pause program for 1 millisecond, helps with randomness as time is used as 
    // randomness seed
    usleep(1000); 
    // Shuffle 'work'. A = 1st half of L (index values), b = 2nd half.
    int a = 0;
    int b = len / 2;

    // Get current time in nanoseconds
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    unsigned int seed = ts.tv_nsec;

    // Set random seed based on the current time in nanoseconds
    srand(seed);
    
    for (int i = 0; i < len; i++) {
        // Check if either 'a' or 'b' refer to an element that is not available.
        if (a >= len/2 && b <= len) {
            memcpy((char*)work + i * size, (char*)L + b * size, size);
            b++;
        }
        else if (b >= len && a <= len/2) {
            memcpy((char*)work + i * size, (char*)L + a * size, size);
            a++;
        }
        // Randomly add either 'a' or 'b' to 'work'
        else if (rand_r(&seed) % 2 == 0)  {
            memcpy((char*)work + i * size, (char*)L + a * size, size);
            a++;
        }
        else {
            memcpy((char*)work + i * size, (char*)L + b * size, size);
            b++;
        }
    }

    // Move contents of work back to L
    memcpy(L, work, len * size);
}


void riffle(void *L, int len, int size, int N) {
    // Create work array and run riffle_once N times
    void *work = malloc(len * size);
    for (int i = 0; i < N; i++) {
        riffle_once(L, len, size, work);
    }
    free(work);
}


int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *)){
    // Copy original contents of L and shuffle L.
    void *og_L = malloc(len * size);
    memcpy(og_L, L, len * size);
    riffle(L, len, size, 1);

    // Compare original L to shuffled L.
    for (int i = 0; i < len; i++) {
        int count = 0;
        // Count how many times i occurs in L.
        for (int j = 0; j < len; j++) {
            if (cmp((char *)L + i * size, (char *)L + j * size) == 0) {
                count++;
            }
        }

        // If element occurs more than or less than once in L.
        if (count != 1) {
            free (og_L);
            return 0; 
        }
    }

    // Shuffled L contains all elements of original L, vice versa.
    free (og_L);
    return 1;
}

int cmp_integer(void *a, void *b) {
    // Cast void to int
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    if (int_a > int_b) {
        return 1;
    } else if (int_a < int_b) {
        return -1;
    } else {
        return 0;
    }
}

int cmp_string(void *a, void *b) {
    // Cast void to char
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;

    return strcmp(str_a, str_b);
}

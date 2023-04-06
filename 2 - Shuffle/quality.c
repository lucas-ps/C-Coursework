#include <stdio.h>
#include "riffle.c"
#include "quality.h"

float quality(int *numbers, int len){
    // Check if subsequent item is greater, incriment 'count' if so.
    int count = 0;
    int size = sizeof(int);
    for (int i = 0; i < len; i++) {
        if (cmp_integer(numbers + i * size, numbers + (i + 1) * size) > 0) {
            count++;
        }
    }
    return (float) count/(len);
}

float average_quality(int N, int shuffles, int trials){
    int numbers[N];
    float results[trials];
    float qualityValue;

    // Start trials
    for (int i = 0; i < trials; i++) {
        // Create 'numbers'
        for (int i = 0; i < N; i++) {
            numbers[i] = i;
        }   
        // Shuffle 'shuffles' times
        riffle(numbers, N, sizeof(int), shuffles);
        
        /*for (int i = 0; i < N; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");*/

        // Write quality to 'results' and repeat
        qualityValue = quality(numbers, N);
        results[i] = qualityValue;
        //printf("Trial %i quality: %f\n", i+1, qualityValue);
    }   
    
    // Get average of values in 'results'
    float total = 0.0;
    for (int i = 0; i < trials; i++) {
        total += results[i];
    }
    float average = total / trials;
    return average;
}

int main() {
    for (int i = 1; i <= 15; i++) {
        float quality = average_quality(50, i, 30);
        printf("Average quality for %i shuffles: %.3f\n", i, quality);
    }

    return 0;
}
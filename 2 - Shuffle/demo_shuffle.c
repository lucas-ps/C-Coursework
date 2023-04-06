#include <stdio.h>
#include "riffle.c"

int main() {
    // Shuffle an array of integers 1 - 20
    int ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
                    18, 19, 20};
    riffle(ints, 20, sizeof(int), 10);
    for (int i = 0; i <= 19; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");

    // Shuffle an array of Greek numbers
    char *greek[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta", 
                        "eta", "theta", "iota", "kappa", "lambda", "mu" };
    riffle(greek, 12, sizeof(char *), 10);
    
    for (int i = 0; i <= 11; i++) {
        printf("%s ", greek[i]);
    }
    printf("\n");
    
    if (check_shuffle(greek, 11, sizeof(char *), cmp_string) == 1) {
        printf("Shuffle on greek numbers valid.\n");
    } else {printf("Shuffle on greek numbers invalid.\n");}

    if (check_shuffle(ints, 19, sizeof(int), cmp_integer) == 1) {
        printf("Shuffle on greek numbers valid.\n");
    } else {printf("Shuffle on greek numbers invalid.\n");}

    return 0;
}


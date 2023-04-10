#include <stdio.h>
#include <stdlib.h>
#include "beggar.c"

int main(int argc, char **argv) {
    int players = 3;
    int trials = 100;

    if (argc == 3) {
        if (atoi(argv[1]) > 51 || atoi(argv[1]) < 2) {
            printf("Invalid player number input. Please choose a player number between 2 and 51\n");
            return 1;
        }
        players = atoi(argv[1]);
        trials = atoi(argv[2]);
    }

    stats_t game_stats = statistics(players, trials);
    printf("Shortest: %d\n", game_stats.shortest);
    printf("Longest: %d\n", game_stats.longest);
    printf("Average: %.2f\n", game_stats.average);
    return 0;
}

// gcc -g -I/opt/homebrew/include byn.c -o byn -L/opt/homebrew/lib -lgsl -lgslcblas -lm && ./byn
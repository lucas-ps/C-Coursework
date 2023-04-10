#include <stdio.h>
#include <stdlib.h>
#include "beggar.c"

/**
 * @brief Prints out statistics for beggar games of a certain player count.
 * 
 * @param argc The number of arguments passed to the program.
 * @param argv The arguments passed (player count, number of trials to do)
 * @return 0 if successful, 1 if invalid arguments or other error.
 */
int main(int argc, char **argv) {
    int players = 3;
    int trials = 100;

    if (argc == 3) {
        if (atoi(argv[1]) > 51 || atoi(argv[1]) < 2) {
            printf("Invalid player number input. Please choose a player number between 2 and 51.\n");
            return 1;
        }
        players = atoi(argv[1]);
        if (atoi(argv[2]) < 1) {
            printf("Invalid trial number input. Please choose a trial number above 0.\n");
            return 1;
        }

        trials = atoi(argv[2]);
    }

    stats_t game_stats = statistics(players, trials);
    printf("Shortest: %d\n", game_stats.shortest);
    printf("Longest: %d\n", game_stats.longest);
    printf("Average: %.2f\n", game_stats.average);
    return 0;
}

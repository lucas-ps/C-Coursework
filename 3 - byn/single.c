#include <stdio.h>
#include "beggar.c"

/**
 * @brief Runs a single beggar-your-neighbour game and prints out the details of
 * each round.
 * 
 *
 * @param argc The amount of arguments passed to the program.
 * @param argv Argument for beggar (player number).
 * @return 1 if invalid arguments or other error, 0 if success.
 */
int main(int argc, char **argv) {
    int players = 3;

    if (argc == 2) {
        if (atoi(argv[1]) > 51 || atoi(argv[1]) < 2) {
            printf("Invalid player number input. Please choose a player number between 2 and 51\n");
            return 1;
        }
        players = atoi(argv[1]);
    }

    beggar(players, NULL, 1);
    return 0;
}

// gcc -g -I/opt/homebrew/include single.c -o single -L/opt/homebrew/lib -lgsl -lgslcblas -lm && ./single 
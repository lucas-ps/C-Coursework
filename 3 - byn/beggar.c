#include <stdio.h>
#include "beggar.h"

// gcc -I/opt/homebrew/include beggar.c -o beggar -L/opt/homebrew/lib -lgsl -lgslcblas -lm && ./beggar

int beggar(int Nplayers, int *deck, int talkative){
    // Initialize necessary variables (players' hands, card pile, turn count, etc.)
    // While the game is not finished, execute the following
    // Determine the current player
    // Call take_turn function for the current player and the card pile.
    // Check if the returned reward is not empty
    // If it's not empty, add the reward cards to the previous player's hand
    // Update the current player
    // Increment the turn count
    // Return the total number of turns
    return 0;
}

int finished(int **players, int num_players){
    int alive_players = 0;

    // Count number of players with no cards.
    for (int i = 0; i < num_players; i++) {
        if (players[i] > 0) {
            alive_players++;
        }
    }
    // Game finished
    if (alive_players == 1){ return 1;}
    // Game not finished
    else { return 0; }
}

int take_turn(int *player, int *pile){
    // Check if the top card of the pile is a penalty card, calculate penalty.
    int penalty = 0;
    switch (pile[0]) {
    case 11: // Jack
        penalty = 1;
        break;
    case 12: // Queen
        penalty = 2;
        break;
    case 13: // King
        penalty = 3;
        break;
    case 14: // Ace
        penalty = 4;
        break;
    }
    // If player plays another penalty card during penalty phase, the 
    // player after must pay the new penalty

    // If player doesn't play a penalty card during the penalty phase, return 
    // the pile as a reward.

    // If penalty = 0, player lays down one card, and game proceeds to the next 
    // player
    return 0;
}

stats_t statistics(int Nplayers, int games){
    stats_t stats;

    int total = 0;
    stats.shortest = 9999999;
    stats.longest = 0;
    
    for (int i = 0; i < games; i++) {
        int result = beggar(Nplayers, NULL, 0);
        if (result < stats.shortest) { stats.shortest = result; }
        if (result > stats.longest) { stats.longest = result; }
        total += result;
    }

    stats.average = total / games;
    return stats;
}
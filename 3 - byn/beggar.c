#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "beggar.h"
#include "shuffle.h"

int beggar(int Nplayers, int *deck, int talkative) {
    int players[Nplayers][52];
    // Set player's deck values to 0.
    for (int i = 0; i < Nplayers; i++) {
        for (int j = 0; j < 52; j++) {
            players[i][j] = 0;
        }
    }

    int pile[52] = {0};

    if (!deck) {
        deck = generate_deck();
    }

    for (int i = 0; i < 52; i++) {
        players[i % Nplayers][i / Nplayers] = deck[i];
    }

    int current_player = 0;
    int turn = 0;
    char output[200];
    int passes = 0;
    int next_player = 0;
    int prev_player = 0;
    int penalty_amount = 0;

    while (!finished(players, Nplayers)) {
        turn++;
        int next_player = (current_player + 1) % Nplayers;
        while (players[next_player][0] == 0) {
            next_player = (next_player + 1) % Nplayers;
        }

        int players_before[Nplayers][52];
        for (int i = 0; i < Nplayers; i++) {
            for (int j = 0; j < 52; j++) {
                players_before[i][j] = players[i][j]; 
            }
        }

        if (talkative) {
            print_details_of_round(players, pile, turn-passes, output, Nplayers, current_player);
        }

        int result = take_turn(players[current_player], pile);
        // Update output message based on result
        if (result == 0) {
            strcpy(output, "Skip player out of game.\n");
            passes++;
        } else if (result == 1) {
            // Add pile to previous players deck
            give_deck_to_player(players[prev_player], pile);

            // Get string of cards played
            //printf("Penalty amount: %d\n", penalty_amount);
            char *cards_taken = (char*)malloc(sizeof(char) * 1024);
            cards_taken[0] = '\0'; 
            for (int i = 0; i < penalty_amount; i++) {
                //printf("%d\n", players_before[current_player][i]);
                char card_str[4];
                snprintf(card_str, 4, "%d", players_before[current_player][i]); 
                strcat(cards_taken, card_str);
                if (i < penalty_amount - 1) strcat(cards_taken, ", ");
            }
            int next_next_player = (current_player + 1) % Nplayers;
            while (players[next_player][0] == 0) {
                next_player = (next_player + 1) % Nplayers;
            }
            sprintf(output, "Player %d laid %s without laying a penalty card, so the pile at the end of last turn is given to player %d. \nPile now empty so next player %d to lay a single card. \n",
            current_player, cards_taken, prev_player, next_next_player);
            current_player = next_player;
            take_turn(players[current_player], pile);
        } else if (result == 2 || pile[0] > 10) {
            penalty_amount = pile[0]-10;
            sprintf(output, "Card laid by player %d was a penalty card, %d, so now player %d to lay %d cards. \n", 
            current_player, pile[0], next_player, penalty_amount);
        } else {
            strcpy(output, "Plays a card.\n");
            sprintf(output, "Top card in pile is %d, so player %d should lay a single card. \n", 
            pile[0], next_player);

        }

        // Move to the next player
        prev_player = current_player;
        current_player = next_player;
    }

    // Find the winner
    int winner = -1;
    for (int i = 0; i < Nplayers; i++) {
        if (players[i][0] > 0) {
            winner = i;
            break;
        }
    }

    if (talkative) {
        printf("Player %d wins after %d turns.\n", winner, turn);
    }

    if (deck != NULL) {
        free(deck);
    }

    return turn-1;
}

int take_turn(int *player, int *pile){
    // Return penalty case
    // Check if player is still in the game
    if (player[0] == 0) {
        return 0;
    }

    if (pile[0] > 10) {
        int penalty = pile[0] - 10;

        int cards_played = 0;
        while (penalty > 0) {
            add_player_card_to_pile(player, pile);
            cards_played++;
            // Case 2, previous player played a penalty card, current player played a penalty card and cancelled their penalty.
            if (pile[0] > 10) {
                return 2;
            }
            penalty--;
        }
        // Case 1, previous player played a penalty card, current player did not. Current player pays penalty.
        return 1; 
    }

    // Case 3, previous player did not play a penalty card, current player plays a card
    add_player_card_to_pile(player, pile);
    return 3;
}


void give_deck_to_player(int *player, int *deck) {
    // Find the end of the deck and player's card arrays (the first 0 found)
    int end_of_player_cards = find_end_of_deck(player);;
    int end_of_deck_cards = find_end_of_deck(deck);;

    // Copy contents of deck to end of player's card array
    for (int i = 0; i < end_of_deck_cards; i++) {
        player[end_of_player_cards + i] = deck[i];
    }

    // Reset deck.
    for (int i = 0; i < 52; i++) {
        deck[i] = 0;
    }
}

void print_details_of_round(int players[][52], int *pile, int turn, char *output, 
int Nplayers, int current_player) {
    printf("Turn %d. \n", turn-1);
    printf("%s", output);

    // Print main deck
    if (pile[0] != 0){ printf("Pile:  %d", pile[0]); }
    else{ printf("Pile:   "); }
    for (int i = 1; i < find_end_of_deck(pile); i++) {
        printf(", %d", pile[i]);
    }
    printf("\n");
    
    // Print player decks
    for (int i = 0; i < Nplayers; i++) {
        if (i == current_player) { printf("*   %d: ", i); }
        else { printf("    %d: ", i); }

        for (int j = 0; j < 52 && players[i][j] != 0; j++) {
            printf("%d", players[i][j]);
            if (j < 51 && players[i][j + 1] != 0) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("\n");

}


int find_end_of_deck(int *array) {
    for (int i = 0; i < 51; i++) {
        if (array[i] == 0) {
            return i;
        }
    }
    return -1;
}

int finished(int (*players)[52], int num_players){
    int alive_players = 0;

    // Count number of players with no cards.
    for (int i = 0; i < num_players; i++) {
        if (players[i][0] > 0) {
            alive_players++;
        }
    }
    // Game finished
    if (alive_players == 1){ return 1;}
    // Game not finished
    else { return 0; }
}

void add_player_card_to_pile(int *player, int *pile){
    if (player[0] == 0) {
        return;
    }

    // Add player's card start of deck array, discard last item (should be 0).
    memmove(pile + 1, pile, 51 * sizeof(int));
    pile[0] = player[0];

    // Remove top card from players cards array, set last index as 0.
    memmove(player, player + 1, 51 * sizeof(int));
    player[51] = 0;
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

int* generate_deck() {
    // Generate a deck, 2-12, where 11, 12, 13, 14 are Jack, Queen, King and Ace.
    int* deck = (int*) malloc(52 * sizeof(int));
    int i = 0;

    for (int suit = 0; suit < 4; ++suit) {
        for (int value = 2; value <= 14; ++value) {
            deck[i] = value;
            i++;
        }
    }

    // Shuffle the deck using shuffle.c
    int seed = -1;  /*  Seed with time */
    shuffle(deck, 52, seed);
    return deck;
}

int main(int argc, char **argv) {    
    int result = beggar(3, NULL, 1);
    printf("%d\n", result);
}

// gcc -I/opt/homebrew/include beggar.c -o beggar -L/opt/homebrew/lib -lgsl -lgslcblas -lm && ./beggar

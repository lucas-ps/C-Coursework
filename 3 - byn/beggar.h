#ifndef BEGGAR_H
#define BEGGAR_H
#include "shuffle.c"

/*// Player struct
typedef struct {
    int id;
    card *cards;
    int num_cards;
} player_t;*/

/**
 * @brief A struct to hold details of shortest, average and longest 
 * games with Nplayers.
 * 
 */
typedef struct {
    int shortest;
    int longest;
    float average;
} stats_t;

/**
 * @brief plays a single beggar your neighbour game with 'Nplayers' players
 * using a provided 'deck'. If 'talkative' is not zero, the details of the game 
 * will be printed. The number of turns to complete the game is returned.
 * 
 * @param Nplayers The number of players.
 * @param deck The deck to use.
 * @param talkative Whether to print the game details or not.
 * @return int The number of turns it takes to complete the game.
 */
int beggar(int Nplayers, int *deck, int talkative);

void give_deck_to_player(int *player, int *deck);

/**
 * @brief Prints out details of a round if 'talkative' is enabled.
 * 
 *
 * @param players The players decks array.
 * @param pile The current main pile.
 * @param turn How many turns have been played so far.
 * @param output The string to output before printing piles.
 * @param Nplayers The number of players in the game.
 * @param current_player The current player.
 */
void print_details_of_round(int players[][52], int *pile, int turn, char *output, 
int Nplayers, int current_player);

/**
 * @brief Finds the end of a card deck (index of first zero - non card item)
 * 
 * @param array The deck array to search.
 * @return The index of the first zero.
 */
int find_end_of_deck(int *array);

/**
 * @brief returns 1 if one player has all the cards and the others have none.
 * 
 * @param players The player's decks.
 * @param num_players The number of players.
 * @return int 0 If the game is not finished, 1 if the game is.
 */
int finished(int (*players)[52], int num_players);

/**
 * @brief Adds a card to the pile from the players deck, removes that card from
 * the player's deck.
 * 
 *
 * @param player The player's deck.
 * @param pile The main pile.
 */
void add_player_card_to_pile(int *player, int *pile);

/**
 * @brief Plays a trurn for the current player, takes in the cards held by a 
 * player and the current main pile of cards. Update the player’s cards and the
 * main pile after a turn and returns 1 if there is a 'reward' for the previous 
 * player.
 * 
 * @param player The current player's deck.
 * @param pile The main pile.
 * @return int Return penalty case, and penalty size. eg. 31 = case 3, penalty 1 card.
 */
int take_turn(int *player, int *pile);

/**
 * @brief uses 'beggar' function to calculate the shortest, average and longest 
 * games with Nplayers. Returns a 'Stats' struct with these details.
 * 
 * @param Nplayers Number of players per game.
 * @param games Number of games to play.
 * @return Stats 
 */
stats_t statistics(int Nplayers, int games);

/**
 * @brief Generates a deck (array of numbers 2-14, appearing 4 times each). 
 * Where 11, 12, 13, 14 are Jack, Queen, King and Ace. Uses 'shuffle.c'.
 * 
 * @return The generated deck array.
 */
int* generate_deck();

#endif
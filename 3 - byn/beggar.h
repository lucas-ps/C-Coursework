#ifndef BEGGAR_H
#define BEGGAR_H
#include "shuffle.c"

// Card struct
typedef struct {
    int value;
    struct card *next;
    struct card *prev;
} card_t;

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

/**
 * @brief returns 1 if one player has all the cards and the others have none.
 * 
 * @param players The player's decks.
 * @param num_players The number of players.
 * @return int 0 If the game is not finished, 1 if the game is.
 */
int finished(int **players, int num_players);

/**
 * @brief Called to get the reward after a turn, takes in the cards held by a 
 * player and the current main pile of cards. Update the player’s cards and the
 * main pile after a turn and returns a 'reward' for the previous player if they
 * don't lay a penalty card in response to the top card in the main pile.
 * 
 * @param player Current player's pile.
 * @param pile Main pile.
 * @return int* The reward cards.
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

#endif
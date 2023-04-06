#ifndef BEGGAR_H
#define BEGGAR_H

// Constants for penalty card values
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11

// Constants for the number of cards to pay as penalty
#define ACE_PENALTY 4
#define KING_PENALTY 3
#define QUEEN_PENALTY 2
#define JACK_PENALTY 1

// Card struct
typedef struct {
    int value;
    struct card *next;
    struct card *prev;
} card_t;

// Player struct
typedef struct {
    int id;
    card *cards;
    int num_cards;
} player_t;



/**
 * @brief plays a single beggar your neighbour game with 'Nplayers' players
 * using a provided 'deck'. If 'talkative' is not zero, the details of the game 
 * will be printed. The number of turns to complete the game is returned.
 * 
 * @param Nplayers the number of players.
 * @param deck the deck to use.
 * @param talkative wheter to print the game details or not.
 * @return int the number of turns it takes to complete the game.
 */
int beggar(int Nplayers, int *deck, int talkative);

/**
 * @brief returns 1 if one player has all the cards and the others have none.
 * 
 * @param players the player's decks.
 * @param num_players the number of players.
 * @return int 0 if the game is not finished, 1 if the game is.
 */
int finished(int **players, int num_players);

/**
 * @brief Called to get the reward after a turn, takes in the cards held by a 
 * player and the current main pile of cards. Update the player’s cards and the
 * main pile after a turn and returns a 'reward' for the previous player if they
 * don't lay a penalty card in response to the top card in the main pile.
 * 
 * @param player current player's pile.
 * @param pile main pile.
 * @param pile_size size of the pile.
 * @param reward_size size of the reward.
 * @return int* the reward.
 */
int *take_turn(int *player, int **pile, int *pile_size, int *reward_size);

void shuffle(int *array, size_t n);

#endif
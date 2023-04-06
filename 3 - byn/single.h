#ifndef SINGLE_H
#define SINGLE_H

/**
 * @brief takes the number of players as a command line argument (in main) and 
 * prints details of a game played with that many players.
 * 
 * @param num_players the number of players.
 * @param deck the deck of cards.
 * @param talkative whether or not to print details of the game.
 * @return int the number of turns to complete the game. TODO: is this right?
 */
int play_single_game(int num_players, int *deck, int talkative);

#endif
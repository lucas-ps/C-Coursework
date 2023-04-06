#ifndef BYN_H
#define BYN_H

/**
 * @brief a struct to hold details of shortest, average and longest 
 * games with Nplayers.
 * 
 */
typedef struct {
    int shortest;
    int longest;
    float average;
} stats_t;

/**
 * @brief uses 'beggar' function to calculate the shortest, average and longest 
 * games with Nplayers. Returns a 'Stats' struct with these details.
 * 
 * @param max_players 
 * @param num_trials 
 * @return Stats 
 */
stats_t statistics(int max_players, int num_trials);

#endif
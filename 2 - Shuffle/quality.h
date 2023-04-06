#ifndef QUALITY_H
#define QUALITY_H

/**
 * @brief Evaluates how well an array has been shuffled by calculating a quality 
 * metric, defined as the fraction of times the second item of two adjacent 
 * items is larger than the first. 
 * 
 * @param numbers Array of numbers to shuffle.
 * @param len Length of array.
 * @return float quality value.
 */
float quality(int *numbers, int len);

/**
 * @brief Evaluates the average quality of a riffle shuffle on an array that 
 * contains integers 0 to N-1, sfuffling the array 'shuffles' times. 
 * 
 * @param N Integers to shuffle.
 * @param shuffles Number of times to shuffle.
 * @param trials  Number of trials.
 * @return float Quality value.
 */
float average_quality(int N, int shuffles, int trials);

#endif

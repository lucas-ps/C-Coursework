#ifndef RIFFLE_H
#define RIFFLE_H

/**
 * @brief performs a single riffle shuffle on L with a number of elements len, 
 * the size of each element in bytes size, and a workspace array work of at 
 * least the same size as L.
 * 
 * @param L Array to shuffle.
 * @param len Number of elements in L.
 * @param size The size of each element.
 * @param work Workspace array used as a temporary storage array.
 */
void riffle_once(void *L, int len, int size, void *work);

/**
 * @brief Calls riffle_once N times to shuffle the array thoroughly.
 * 
 * @param L Array to shuffle.
 * @param len Number of elements in L.
 * @param size Size of each element.
 * @param N Number of times to shuffle.
 */
void riffle(void *L, int len, int size, int N);

/**
 * @brief checks that the riffle shuffle implementation respects that all 
 * elements in the original array are in the shuffled array and vice versa. Uses 
 * a comparison function cmp that casts its arguments to the appropriate type 
 * then returns -1, 0, or 1 if the first argument is greater than, equal to, or 
 * less than the second argument.
 * 
 * @param L Array to shuffle.
 * @param len Number of elements in L.
 * @param size Size of each element.
 * @param cmp Comparison function for the datatype in the array.
 * @return int 1 if shuffle is successful, 0 otherwise.
 */
int check_shuffle(void *L, int len, int size, int (*cmp)(void *, void *));

/**
 * @brief Compares two integers, returns 1 if a > b, -1 if a < b, 0 if they are 
 * equal.
 * 
 * @param a first integer to compare
 * @param b second integer to compare
 * @return int 1 if a > b, -1 if a < b, 0 if they are equal.
 */
int cmp_integer(void *a, void *b);

/**
 * @brief Compares two strings (*char) using strcmp()
 * 
 * @param a first string to compare
 * @param b second string to compare
 * @return int the value returned by strcmp()
 */
int cmp_string(void *a, void *b);

#endif

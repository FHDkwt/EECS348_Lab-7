#ifndef FOOTBALL_H
#define FOOTBALL_H

/**
 * @brief Return the number of possible combinations to add up to `points`
 * 
 * @param points
 * @return int 
 */
int count_combinations(int points);

/**
 * @brief Print a formatted table of all possible combinations that add up to
 * `points`
 * 
 * @param points
 */
void print_combinations(int points);

/**
 * @brief Find and print all possible scoring combinations for a given score
 * 
 * @param score
 */
void find_combinations(int score);

#endif /* FOOTBALL_H */

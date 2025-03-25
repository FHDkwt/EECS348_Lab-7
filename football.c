/** football.c
This file contains implementation of functions for Football Score Possibilities program. It calculates and prints all possible combinations of NFL scoring plays (Touchdown + 2pt,
Touchdown + FG, Touchdown, Field Goal, Safety) that sum to a given score.
*/
#include <stdio.h>
#include "football.h" // including header file with function declarations

// defining function to print all possible combinations of NFL scoring plays that sum to given points
void print_combinations(int points) {
    // declaring variables to represent no. of each type of scoring play
    int td_2pt, td_fg, td, fg, safety;
    int count = 0; // initializing counter for no. of valid combinations found

    // printing header for  combinations table
    printf("Possible combinations of scoring plays if a team's score is %d:\n", points);

    /** nested loops to iterate through all possible combinations of scoring plays, each loop represents a type of scoring play and condition ensures we don't exceed target score
        */
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) { // touchdown + 2pt (8 points each)
        for (td_fg = 0; td_fg * 7 <= points - td_2pt * 8; td_fg++) { // touchdown + FG (7 points each)
            for (td = 0; td * 6 <= points - td_2pt * 8 - td_fg * 7; td++) { // touchdown (6 points each)
                for (fg = 0; fg * 3 <= points - td_2pt * 8 - td_fg * 7 - td * 6; fg++) { // field goal (3 points each)
                    // calculating no. of Safeties needed to reach target score
                    safety = (points - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2;

                    // checking if combination of plays exactly matches target score
                    if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == points) {
                        // printing valid combination in specified format
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td_2pt, td_fg, td, fg, safety);
                        count++; // incrementing counter for valid combinations
                    }
                }
            }
        }
    }
}

// defining function count the no. of possible combinations of NFL scoring plays that sum to given points
int count_combinations(int points) {
    // declaring variables to represent no. of each type of scoring play
    int td_2pt, td_fg, td, fg, safety;
    int count = 0; // initializing counter for no. of valid combinations

    /** Nested loops to iterate through all possible combinations of scoring plays,similar to print_combinations, but only counts combinations instead of printing them
        */
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) { // touchdown + 2pt (8 points each)
        for (td_fg = 0; td_fg * 7 <= points - td_2pt * 8; td_fg++) { // touchdown + FG (7 points each)
            for (td = 0; td * 6 <= points - td_2pt * 8 - td_fg * 7; td++) { // touchdown (6 points each)
                for (fg = 0; fg * 3 <= points - td_2pt * 8 - td_fg * 7 - td * 6; fg++) { // field goal (3 points each)
                    // calculating no. of Safeties (2 points each) needed to reach target score
                    safety = (points - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2;

                    // checking if combination of plays exactly matches target score
                    if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == points) {
                        count++; // incrementing counter for valid combinations
                    }
                }
            }
        }
    }

    return count; // returning total no. of valid combinations
}

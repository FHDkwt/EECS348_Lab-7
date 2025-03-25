/** football_main.c
This file contains main function for the Football Score Possibilities program.
It handles user input,validates the NFL score and calls function to print all possible combinations of scoring plays that result in the given score.
*/
#include <stdio.h>
#include "football.h" // including header file with function declarations for print_combinations

// main function
int main() {
    int score; // declaring variable to store the user-entered NFL score
    printf("Enter 0 or 1 to STOP\n"); // prompting user to terminate program
    while (1) { // infinite loop to repeatedly ask for scores until the user terminates program
        // prompting user to enter an NFL score
        printf("Enter the NFL score: ");
        scanf("%d", &score); // reading score from user input
        if (score <= 1) {
            printf("Program terminated.\n"); // exiting loop to terminate program
            break;
        }
         // validating score: NFL scores must be 2 or higher to have valid combinations
        if (score < 2) {
            printf("Invalid score! Score must be 2 or higher.\n");
            continue;
        }
        print_combinations(score); // call the function from football.c to compute and print combinations
    }

    return 0;
}

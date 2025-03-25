#include <stdio.h>
#include "football.h"

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }
        if (score < 2) {
            printf("Invalid score! Score must be 2 or higher.\n");
            continue;
        }
        print_combinations(score);
    }

    return 0;
}

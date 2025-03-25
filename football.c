#include <stdio.h>
#include "football.h"

void print_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;
    int count = 0; 
    printf("Possible combinations of scoring plays if a team's score is %d:\n", points);
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        for (td_fg = 0; td_fg * 7 <= points - td_2pt * 8; td_fg++) { 
            for (td = 0; td * 6 <= points - td_2pt * 8 - td_fg * 7; td++) {
                for (fg = 0; fg * 3 <= points - td_2pt * 8 - td_fg * 7 - td * 6; fg++) { 
                    safety = (points - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2; 
                    if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == points) {
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               td_2pt, td_fg, td, fg, safety);
                        count++; 
                    }
                }
            }
        }
    }
}

int count_combinations(int points) {
    int td_2pt, td_fg, td, fg, safety;
    int count = 0;
    for (td_2pt = 0; td_2pt * 8 <= points; td_2pt++) {
        for (td_fg = 0; td_fg * 7 <= points - td_2pt * 8; td_fg++) {
            for (td = 0; td * 6 <= points - td_2pt * 8 - td_fg * 7; td++) {
                for (fg = 0; fg * 3 <= points - td_2pt * 8 - td_fg * 7 - td * 6; fg++) {
                    safety = (points - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2;
                    if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == points) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

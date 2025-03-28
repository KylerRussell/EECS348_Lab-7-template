#include <stdio.h> // include the standard input output library
#include "football.h" // include the football function

/*
 Scoring plays:
 - Touchdown + 2pt conversion: 8 points
 - Touchdown + 1pt conversion (extra point): 7 points
 - Touchdown (no conversion): 6 points
 - Field goal: 3 points
 - Safety: 2 points
 */

// For count combinations we use nested loops to iterate over all possible counts of each scoring type and if the combination sums to exactly points then we increment a counter and finally return the counter
int count_combinations(int points) { // define the count combination function
    int count = 0; // create integer variable count and set to 0
    for (int td2 = 0; td2 <= points / 8; td2++) { // loop over how many TD+2 conversions possible
        for (int td1 = 0; td1 <= points / 7; td1++) { // loop over how many TD+1 conversions possible
            for (int td = 0; td <= points / 6; td++) { // loop over how many TD conversions possible
                for (int fg = 0; fg <= points / 3; fg++) { // loop over how many FG possible
                    for (int safety = 0; safety <= points / 2; safety++) { // loop over how many safeties possible
                        if (8 * td2 + 7 * td1 + 6 * td + 3 * fg + 2 * safety == points) {  // check if the sum of scoring plays equal to the target points
                            count++; // if it matches increment the count of valid combinations
                        }
                    }
                }
            }
        }
    }
    return count; // return the total number of valid combinations
}

// For print combinations we use the same nested loop approach as in count combinations and whenever a combination matches points it prints the combination
void print_combinations(int points) { // define the print combinations functions
    for (int td2 = 0; td2 <= points / 8; td2++) { // loop over how many TD+2 conversions possible
        for (int td1 = 0; td1 <= points / 7; td1++) { // loop over how many TD+1 conversions possible
            for (int td = 0; td <= points / 6; td++) { // loop over how many TD conversions possible
                for (int fg = 0; fg <= points / 3; fg++) { // loop over how many FG possible
                    for (int safety = 0; safety <= points / 2; safety++) { // loop over how many safeties possible
                        if (8 * td2 + 7 * td1 + 6 * td + 3 * fg + 2 * safety == points) { // check if the sum of scoring plays equal to the target points
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, td, fg, safety); // print the valid combination in a formatted line
                        }
                    }
                }
            }
        }
    }
}

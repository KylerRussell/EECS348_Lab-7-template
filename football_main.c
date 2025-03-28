#include <stdio.h> // include the standard input output library
#include "football.h" // include the football function

int main(int argc, char *argv[]) { // define the main function
    int score; // declare an integer variable score to store the user's input score
    while (1) { // start an infinite loop we break when we need to
        printf("Enter 0 or 1 to STOP\n"); // let user know how to stop
        printf("Enter the NFL score: "); // prompt the user to enter score
        if (scanf("%d", &score) != 1) { // check if integer is not properly read in
            printf("Invalid input. Exiting.\n"); // if it is not properly read in print an error
            break; // break from the infinite loop
        }
        if (score <= 1) { // if score is less than or equal to 1
            break; // break from the infinite loop
        }
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score); // print a header line about the combinations for the entered score
        print_combinations(score); // call the function to print all combinations
        printf("Total combinations: %d\n\n", count_combinations(score)); // print the total nubmer of combinations
    }
    return 0; // return 0 to indicate successful program execution
}

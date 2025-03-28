#include <stdio.h> // include the standard input output library
#include <ctype.h> // include ctype for toupper() funciton to handle scale letters consistently
#include "temperature.h" // include the temperature function

int main(int argc, char *argv[]) { // define the main function
    float temp, converted; // create float variables temp and converted to hold user input and result after converted
    char in_scale, out_scale; // create char variable in_scale and out_scale to hold the user's chose scales'


    while (1) { // start infinite loop to break out of later in code at decided point
        printf("\nEnter temperature value (or a non-number to exit): "); // prompt user for the temperature value
        if (scanf("%f", &temp) != 1) { // check if failure to read a float
            printf("Exiting program.\n"); // if failure to read a float output that the program is exiting
            break; // break from infinite loop and exit program
        }
        printf("Enter input scale (C, F, K): "); // prompt user for input scale
        scanf(" %c", &in_scale); // read a single character with a leading space to skip newline
        in_scale = toupper(in_scale); // convert the character to uppercase to handle c or C the same

        if (in_scale != 'C' && in_scale != 'F' && in_scale != 'K') { // check if valid input scale
            printf("Invalid input scale.\n"); // if invalid, output message about invalid scale
            continue; // start the loop over again
        }
        if (in_scale == 'K' && temp < 0) { // check for valid kelvin
            printf("Invalid temperature: Kelvin cannot be negative.\n"); // if invalid, output message about invalid kelvin
            continue; // start the loop over again
        }

        printf("Enter target scale (C, F, K): "); // prompt user for target scale
        scanf(" %c", &out_scale); // read a single character with a leading space to skip newline
        out_scale = toupper(out_scale); // convert the character to uppercase to handle c or C the same

        if (out_scale != 'C' && out_scale != 'F' && out_scale != 'K') { // chck if valid target scale
            printf("Invalid target scale.\n"); // if invalid, output message about invalid scale
            continue; // start the loop over again
        }
        if (in_scale == out_scale) { // check that the scales are not the same
            printf("Input and target scales are the same. Nothing to convert.\n"); // output that the scales are the same
            continue; // start the loop over again
        }

        float temp_in_celsius; // convert the input temperature to celsius for categorization and conversion
        if (in_scale == 'C') { // if in scale is celsius
            temp_in_celsius = temp; // temp is the desired
        } else if (in_scale == 'F') { // if in scale fahrenheit
            temp_in_celsius = fahrenheit_to_celsius(temp); // convert fahrenheit to celsius
        } else { // else scale is kelvin
            temp_in_celsius = kelvin_to_celsius(temp); // convert kelvin to celsius
        }

        if (out_scale == 'C') { // if out scale is celsius is already in celsius
            converted = temp_in_celsius; // converted already so set it to temp_in_celsius
        } else if (out_scale == 'F') { // if out scale is fahrenheit
            converted = celsius_to_fahrenheit(temp_in_celsius); // convert celsius to fahrenheit
        } else { // else out scale is kelvin
            converted = celsius_to_kelvin(temp_in_celsius); // convert celsius to kelvin
        }

        printf("Converted temperature: %.2f %c\n", converted, out_scale); // print the converted result with two decimal places
        categorize_temperature(temp_in_celsius); // categorize based on the celsius value
    }
    return 0; // return 0 to indicate success
}

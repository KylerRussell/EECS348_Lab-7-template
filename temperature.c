#include <stdio.h> // include the standard input output library
#include "temperature.h" // include the temperature function

float celsius_to_fahrenheit(float celsius) { // define celsius to fahrenheit function
    return (9.0f / 5.0f) * celsius + 32.0f; // convert from celsius to fahrenheit using formula: F = (9/5)*C + 32
}

float fahrenheit_to_celsius(float fahrenheit) { // define fahrenheit to celsius function
    return (5.0f / 9.0f) * (fahrenheit - 32.0f); // convert from fahrenheit to celsius using formula: C = (5/9)*(F - 32)
}

float celsius_to_kelvin(float celsius) { // define celsius to kelvin function
    return celsius + 273.15f; // convert from celsius to kelvin using formula: K = C + 273.15
}

float kelvin_to_celsius(float kelvin) { // define kelvin to celsius function
    return kelvin - 273.15f; // convert from kelvin to celsius using formula: C = K - 273.15
}

float fahrenheit_to_kelvin(float fahrenheit) { // define fahrenheit to kelvin function
    float celsius = fahrenheit_to_celsius(fahrenheit); // convert fahrenheit to celsius
    return celsius_to_kelvin(celsius); // convert celsius to kelvin
}

float kelvin_to_fahrenheit(float kelvin) { // define kelvin to fahrenheit function
    float celsius = kelvin_to_celsius(kelvin); // convert kelvin to celsius
    return celsius_to_fahrenheit(celsius); // convert celsius to fahrenheit
}

/* takes in celsius value and checks if it falls into one of the following categories:
 * < 0: Freezing
 * [0, 10): Cold
 * [10, 25): Comfortable
 * [25, 35): Hot
 * >= 35: Extreme Heat
 * and outputs an advisory message
 */
void categorize_temperature(float celsius) { // define categorize temperature function
    if (celsius < 0) { // check if celsius is below 0
        printf("Category: Freezing. Advisory: Bundle up and stay warm.\n"); // print freezing advisory
    } else if (celsius >= 0 && celsius < 10) { // check if celsius is between 0 and 10
        printf("Category: Cold. Advisory: Wear a jacket.\n"); // print cold advisory
    } else if (celsius >= 10 && celsius < 25) { // check if celsius is between 10 and 25
        printf("Category: Comfortable. Advisory: Enjoy the pleasant weather.\n"); // print comfortable advisory
    } else if (celsius >= 25 && celsius < 35) { // check if celsius is between 25 and 35
        printf("Category: Hot. Advisory: Stay hydrated and take breaks in the shade.\n"); // print hot advisory
    } else {  // if celsius >= 35
        printf("Category: Extreme Heat. Advisory: Stay indoors and avoid strenuous activity.\n"); // print extreme heat advisory
    }
}

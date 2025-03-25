// temperature.c
/** This file contains implementation of functions for Temperature Conversion program. It provides functions to convert temperatures between Celsius,Fahrenheit and Kelvin and to categorize temperature with a weather advisory.
*/
#include <stdio.h>
#include "temperature.h" // including header file with function declarations

// defining function to convert Celsius to Fahrenheit using formula F = (9/5) * C + 32
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}
// defining function to convert Fahrenheit to Celsius using formula C = (5/9) * (F - 32)
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}
// defining function to convert Celsius to Kelvin using formula K = C + 273.15
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
// defining function to convert Kelvin to Celsius using formula C = K - 273.15
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
// defining function to convert Fahrenheit to Kelvin by first converting to Celsius then to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
// defining function to convert Kelvin to Fahrenheit by first converting to Celsius then to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
// defining function to categorize temperature in Celsius and print a weather advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) { // Freezing: Below 0°C
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors.\n");
    } else if (celsius >= 0 && celsius <= 10) { // Cold: 0°C to 10°C
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) { // Comfortable: 10°C to 25°C
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) { // Hot: 25°C to 35°C
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else { // Extreme Heat: Above 35°C
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Avoid outdoor activities.\n");
    }
}

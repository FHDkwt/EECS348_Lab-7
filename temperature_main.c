/** temperature_main.c
This file contains main function for the Temperature Conversion program. It handles user input, performs temperature conversions and categorizes temperature.
*/
#include <stdio.h>
#include "temperature.h" // including header file with function declarations

// main function
int main() {
    float temp, converted_temp; // declaring variables for input and converted temperatures
    int current_scale, target_scale; // declaring variables for current and target temperature scales

    // infinite loop to repeatedly ask for temperature conversions
    while (1) {
        // prompting and reading temperature value
        printf("Enter the temperature: ");
        if (scanf("%f", &temp) != 1) {
            printf("Invalid temperature! Please enter a numeric value.\n");
            while (getchar() != '\n'); // clearing input buffer
            continue;
        }

        // prompting and reading current scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
            printf("Invalid scale! Please enter 1, 2, or 3.\n");
            while (getchar() != '\n'); // clearing input buffer
            continue;
        }

        // validating Kelvin temperature (cannot be negative)
        if (current_scale == 3 && temp < 0) {
            printf("Invalid temperature! Kelvin cannot be negative.\n");
            continue;
        }
        // prompting and reading target scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid scale! Please enter 1, 2, or 3.\n");
            while (getchar() != '\n'); // clearing input buffer
            continue;
        }
        // checking if current and target scales are same
        if (current_scale == target_scale) {
            printf("Error: Current scale and target scale cannot be the same!\n");
            continue;
        }
        // handling conversions from Celsius
        if (current_scale == 1) {
            if (target_scale == 2) {
                converted_temp = celsius_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            } else { // target is Kelvin
                converted_temp = celsius_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            categorize_temperature(temp); // categorizing based on Celsius
        }
        // handling conversions from Fahrenheit
        else if (current_scale == 2) {
            float celsius = fahrenheit_to_celsius(temp); // converting to Celsius first
            if (target_scale == 1) {
                converted_temp = celsius;
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else { // target is Kelvin
                converted_temp = fahrenheit_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            categorize_temperature(celsius); // Categorize based on Celsius
        }
        // handling conversions from Kelvin
        else {
            float celsius = kelvin_to_celsius(temp); // converting to Celsius first
            if (target_scale == 1) {
                converted_temp = celsius;
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else { // target is Fahrenheit
                converted_temp = kelvin_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            }
            categorize_temperature(celsius); // categorizing based on Celsius
        }
        printf("\n"); // adding a newline for readability
    }

    return 0; // returning 0 to indicate successful program execution
}

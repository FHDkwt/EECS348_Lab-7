#include <stdio.h>
#include "temperature.h"

int main() {
    float temp, converted_temp;
    int current_scale, target_scale;

    while (1) {
        printf("Enter the temperature: ");
        if (scanf("%f", &temp) != 1) {
            printf("Invalid temperature! Please enter a numeric value.\n");
            while (getchar() != '\n'); 
            continue;
        }
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
            printf("Invalid scale! Please enter 1, 2, or 3.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (current_scale == 3 && temp < 0) {
            printf("Invalid temperature! Kelvin cannot be negative.\n");
            continue;
        }

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid scale! Please enter 1, 2, or 3.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (current_scale == target_scale) {
            printf("Error: Current scale and target scale cannot be the same!\n");
            continue;
        }
        if (current_scale == 1) {
            if (target_scale == 2) {
                converted_temp = celsius_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            } else { 
                converted_temp = celsius_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            categorize_temperature(temp);
        } else if (current_scale == 2) { 
            float celsius = fahrenheit_to_celsius(temp);
            if (target_scale == 1) {
                converted_temp = celsius;
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else { 
                converted_temp = fahrenheit_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            categorize_temperature(celsius);
        } else { 
            float celsius = kelvin_to_celsius(temp);
            if (target_scale == 1) {
                converted_temp = celsius;
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else { 
                converted_temp = kelvin_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            }
            categorize_temperature(celsius);
        }
        printf("\n");
    }

    return 0;
}

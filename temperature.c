#include <stdio.h>
#include "temperature.h"

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float celsius) {
    return celsius - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

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

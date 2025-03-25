// temperature.h
/** This header file defines the function declarations for Temperature Conversion program. It provides interface for functions that convert temperatures between Celsius, Fahrenheit
and Kelvin, and categorize temperature with a weather advisory.
*/
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 * This function converts a temperature from Celsius to Fahrenheit using formula
 * Fahrenheit = (Celsius * 9/5) + 32
 * 
 * @param celsius
 * @return float
 */
float celsius_to_fahrenheit(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 * This function converts a temperature from Fahrenheit to Celsius using formula
 * Celsius = (Fahrenheit - 32) * 5/9
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 * This function converts a temperature from Celsius to Kelvin using formula
 * Kelvin = Celsius + 273.15
 * @param celsius
 * @return float
 */
float celsius_to_kelvin(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 * This function converts a temperature from Kelvin to Celsius using formula
 * Celsius = Kelvin - 273.15
 * @param celsius
 * @return float
 */
float kelvin_to_celsius(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Kelvin
 * This function converts a temperature from Fahrenheit to Kelvin by first converting to Celsius then to Kelvin.
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_kelvin(float fahrenheit);

/**
 * @brief Convert temperature in Kelvin to Fahrenheit
 * This function converts a temperature from Kelvin to Fahrenheit by first converting to Celsius then to Fahrenheit.
 * @param kelvin
 * @return float
 */
float kelvin_to_fahrenheit(float kelvin);

/**
 * @brief Categorize the temperature in Celsius and provide a weather advisory
 * This function categorizes temperature into Freezing, Cold, Comfortable, Hot or Extreme Heat based on Celsius value and prints a corresponding weather advisory.
 * @param celsius
 */
void categorize_temperature(float celsius);

#endif /* TEMPERATURE_H */

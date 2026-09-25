#include <stdio.h>
#include <stdbool.h>

// fucntion that converts tempterature to another scale unit
float temperature_conversion (float temp, char start_units, char end_units) {
    if (start_units == 'F' || start_units == 'f') {
        if (end_units == 'C' || end_units == 'c') {
            return (temp - 32) * 5.0 / 9.0;
        }

        else if (end_units == 'K' || end_units == 'k') {
            return (temp - 32) * 5.0 / 9.0 + 273.15;
        }

        else {
            return temp;
        }
    }

    else if (start_units == 'C' || start_units == 'c') {
        if (end_units == 'F' || end_units == 'f') {
            return (temp * 9.0 / 5.0) + 32;
        }

        else if (end_units == 'K' || end_units == 'k') {
            return temp + 273.15;
        }

        else {
            return temp;
        }
    }

    else if (start_units == 'K' || start_units == 'k') {
        if (end_units == 'F' || end_units == 'f') {
            return (temp - 273.15) * 9.0 / 5.0 + 32;
        }

        else if (end_units == 'C' || end_units == 'c') {
            return (temp - 273.15);
        }

        else {
            return temp;
        }
    }

    else {
        return temp;
    }
}

int main(void) {
    float temp;
    char start_units;
    char end_units;
    char line[100];

    // 1. Get Temperature
    while (true) {
        printf("Enter the temperature: ");
        if (!fgets(line, sizeof(line), stdin)) continue;

        // Check for empty input (user just pressed Enter)
        if (line[0] == '\n' || line[0] == '\0') {
            printf("Input cannot be empty. Please enter a number.\n");
            continue;
        }

        // Validate that it's a valid float
        if (sscanf(line, "%f", &temp) != 1) {
            printf("Invalid temperature, please enter a valid number.\n");
            continue;
        }
        break;
    }

    // 2. Get Current Scale
    while (true) {
        printf("Enter current scale (C, F, or K): ");
        if (!fgets(line, sizeof(line), stdin)) continue;

        // Check for empty input
        if (line[0] == '\n' || line[0] == '\0') {
            printf("Input cannot be empty. Please enter C, F, or K.\n");
            continue;
        }

        if (sscanf(line, " %c", &start_units) != 1 ||
            (start_units != 'C' && start_units != 'c' && 
             start_units != 'F' && start_units != 'f' && 
             start_units != 'K' && start_units != 'k')) {
            printf("Invalid scale. Must be C, F, or K.\n");
            continue;
        }
        break;
    }

    // 3. Get Target Scale
    while (true) {
        printf("Enter scale to convert to (C, F, or K): ");
        if (!fgets(line, sizeof(line), stdin)) continue;

        // Check for empty input
        if (line[0] == '\n' || line[0] == '\0') {
            printf("Input cannot be empty. Please enter C, F, or K.\n");
            continue;
        }

        if (sscanf(line, " %c", &end_units) != 1 ||
            (end_units != 'C' && end_units != 'c' && 
             end_units != 'F' && end_units != 'f' && 
             end_units != 'K' && end_units != 'k')) {
            printf("Invalid scale. Must be C, F, or K.\n");
            continue;
        }
        break;
    }

    printf("\n%.2f %c converts to %.2f %c\n", 
           temp, start_units, temperature_conversion(temp, start_units, end_units), end_units);

    // Weather Advisory - Note: use 'else if' and float so only one category prints!
    float celsius_value = temperature_conversion(temp, start_units, 'C');

    if (temperature_conversion(temp, start_units, 'K') <= 0) {
        printf("Temperature Category: Absolute Zero!\n");
        printf("Weather Advisory: Maybe stay inside, if you are somehow alive.\n");
    }

    else if (celsius_value < 0.0) {
        printf("Temperature Category: Freezing!\n");
        printf("Weather Advisory: Bundle up good, or be frozen!\n");
    } 
    
    else if (celsius_value < 10.0) {
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear some sweatpants, a nice jacket, and maybe a warm drink too.\n");
    } 
    
    else if (celsius_value < 25.0) {
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: Dress with a light jacket or a sweater.\n");
    } 
    
    else if (celsius_value < 35.0) {
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Dress light, stay hydrated.\n");
    } 
    
    else {
        printf("Temperature Category: Extreme Heat!\n");
        printf("Weather Advisory: Stay cool, and do not go outside!\n");
    }

    return 0;
}

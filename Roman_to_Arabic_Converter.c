#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

// Define constants for Roman numeral values
#define VALUE_I 1
#define VALUE_V 5
#define VALUE_X 10
#define VALUE_L 50
#define VALUE_C 100
#define VALUE_D 500
#define VALUE_M 1000

int roman_to_arabic();

int main(void) {
    printf("10 Roman numeral values will be input and converted into\ntheir equivalent Hindu-Arabic numeric values.\n\n");

    for (int i = 1; i <= 10; i++) {
        printf("Input Roman numeral # %d: ", i);
        if (roman_to_arabic() == -1) { // If error, flush remaining characters of this line
            while (getchar() != '\n'); // Clear the buffer if an error occurred
        }
        printf("\n"); // Newline for the next prompt
    }
    printf("THAT'S ALL FOLKS :)\n");
    return 0;
}

int roman_to_arabic() {
    int arabic = 0, current_value = 0, last_value = 0;
    int first_invalid_char = 0; // Flag to store the first invalid character for error message
    char c = getchar(); // Read the first character

    while (c != '\n') {
        char upper_c = toupper(c); // Convert to uppercase
        printf("%c", upper_c); // Echo the character immediately

        switch (upper_c) {
        case 'I': current_value = VALUE_I; break;
        case 'V': current_value = VALUE_V; break;
        case 'X': current_value = VALUE_X; break;
        case 'L': current_value = VALUE_L; break;
        case 'C': current_value = VALUE_C; break;
        case 'D': current_value = VALUE_D; break;
        case 'M': current_value = VALUE_M; break;
        default:
            if (!first_invalid_char) first_invalid_char = 1; // Set error flag
        }

        if (first_invalid_char) {
            printf(" Error - last character was not valid!!!");
            return -1; // Signal an error occurred
        }

        // Calculate the Arabic value
        if (last_value > 0 && last_value < current_value) {
            arabic += current_value - 2 * last_value;
        }
        else {
            arabic += current_value;
        }

        last_value = current_value;
        c = getchar(); // Continue reading characters
    }

    // Only print the total if no invalid characters were found
    if (!first_invalid_char) {
        printf(" = %d", arabic);
    }

    return arabic;
}

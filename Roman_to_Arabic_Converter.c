#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // For toupper function

int roman_to_arabic(const char roman[]);

int main(void)
{
    char roman[100];
    printf("10 Roman numeral values will be input and converted into their equivalent Hindu-Arabic numeric values.\n");

    for (int i = 1; i <= 10; i++) {
        printf("Input Roman numeral # %d: ", i);
        scanf("%99s", roman);
        printf("%s = %d\n", roman, roman_to_arabic(roman));
    }
    return 0;
}

int roman_to_arabic(const char roman[])
{
    int arabic = 0;
    int current_value, next_value;

    for (int i = 0; roman[i] != '\0'; i++) {
        char r = toupper(roman[i]); // Handle case insensitivity
        switch (r) {
        case 'I': current_value = 1; break;
        case 'V': current_value = 5; break;
        case 'X': current_value = 10; break;
        case 'L': current_value = 50; break;
        case 'C': current_value = 100; break;
        case 'D': current_value = 500; break;
        case 'M': current_value = 1000; break;
        default: current_value = 0; break; // Invalid character handling
        }

        if (roman[i + 1] != '\0') {
            r = toupper(roman[i + 1]); // Next Roman numeral
            switch (r) {
            case 'I': next_value = 1; break;
            case 'V': next_value = 5; break;
            case 'X': next_value = 10; break;
            case 'L': next_value = 50; break;
            case 'C': next_value = 100; break;
            case 'D': next_value = 500; break;
            case 'M': next_value = 1000; break;
            default: next_value = 0; break; // Invalid character handling
            }
        }
        else {
            next_value = 0; // No next character, so no next value
        }

        // Determine if we should add or subtract
        if (current_value < next_value) {
            arabic -= current_value;
        }
        else {
            arabic += current_value;
        }
    }

    return arabic;
}

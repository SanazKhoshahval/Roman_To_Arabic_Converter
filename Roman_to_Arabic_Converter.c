#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int roman_to_arabic(const char roman[]);

int main(void) {
    char roman[100];
    int result;

    printf(" 10 Roman numeral values will be input and converted into\ntheir equivalent Hindu-Arabic numeric values.\n\n");

    for (int i = 1; i <= 10; i++) {
        printf("Input Roman numeral # %d: ", i);
        scanf("%99s", roman);

        for (int j = 0; roman[j] != '\0'; j++) {
            roman[j] = toupper(roman[j]);
        }

        result = roman_to_arabic(roman);
        if (result >= 0) {  // Check if the conversion was successful
            printf("%s = %d \n\n", roman, result);
        }
    }
    printf("THAT'S ALL FOLKS :)\n");
}

int roman_to_arabic(char roman[]) {
    int arabic = 0;
    int current_value = 0;
    int i = 0;

    for (i = 0; roman[i] != '\0'; i++) {
        char r = roman[i];
        switch (r) {
        case 'I': current_value = 1; break;
        case 'V': current_value = 5; break;
        case 'X': current_value = 10; break;
        case 'L': current_value = 50; break;
        case 'C': current_value = 100; break;
        case 'D': current_value = 500; break;
        case 'M': current_value = 1000; break;
        default:
            // Print the part of the string up to the first invalid character
            roman[i + 1] = '\0';  // Terminate string right after the invalid character
            printf("%s Error - last character was not valid!!!\n\n", roman);
            return -1;
        }

        // Calculate the total value assuming the next valid characters
        if (roman[i + 1] != '\0') {
            switch (roman[i + 1]) {
            case 'I': arabic += (current_value < 1) ? -current_value : current_value; break;
            case 'V': arabic += (current_value < 5) ? -current_value : current_value; break;
            case 'X': arabic += (current_value < 10) ? -current_value : current_value; break;
            case 'L': arabic += (current_value < 50) ? -current_value : current_value; break;
            case 'C': arabic += (current_value < 100) ? -current_value : current_value; break;
            case 'D': arabic += (current_value < 500) ? -current_value : current_value; break;
            case 'M': arabic += (current_value < 1000) ? -current_value : current_value; break;
            default:
                continue;  // Keep processing if the next character is valid
            }
        }
        else {
            arabic += current_value; // Add last valid character to total
            break;  // Exit loop if no more characters
        }
    }

    return arabic;
}

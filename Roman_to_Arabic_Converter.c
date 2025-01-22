#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char roman[100];

    printf("10 Roman numeral values will be input and converted into their equivalent Hindu - Arabic numeric values.");

    for (int i = 0; i < 10; i++) {
        printf("Input Roman numeral # %d : /n", i);
        scanf("%99s", roman);
        
    }
}
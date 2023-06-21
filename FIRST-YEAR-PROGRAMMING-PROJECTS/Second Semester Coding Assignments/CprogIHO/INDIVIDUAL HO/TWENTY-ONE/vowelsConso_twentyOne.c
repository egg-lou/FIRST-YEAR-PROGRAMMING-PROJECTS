#include <stdio.h>
#include <conio.h>
#include <string.h>

void CountVowConso(char string[], int *vowelsCount, int *consoCounts);

int main()
{
    char string[100];
    int vowelsCount = 0, consoCounts = 0;

    printf("Input a string: ");
    fgets(string, sizeof(string), stdin);

    CountVowConso(string, &vowelsCount, &consoCounts);

    printf("Vowels: %d\n", vowelsCount);
    printf("Consonants: %d\n", consoCounts);
}

void CountVowConso(char string[], int *vowelsCount, int *consoCounts){
    int index = 0;
    strlwr(string);

    while (*(string + index) != '\0'){
        char letter = *(string + index); 

        if (letter >= 'a' && letter <= 'z'){
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
                (*vowelsCount)++;
            else
                (*consoCounts)++;
        }

        index++;
    }
}
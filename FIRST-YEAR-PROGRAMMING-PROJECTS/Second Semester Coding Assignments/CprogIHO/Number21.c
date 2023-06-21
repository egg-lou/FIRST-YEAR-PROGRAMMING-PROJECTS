#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>


void counter(char *str, int *vowelCount, int *consonantCount){
    *vowelCount = 0;
    *consonantCount = 0;
    int i;
    for(i = 0; *(str + i) != '\0'; i++){
        char ch = tolower(*(str + i));

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch =='u'){
            (*vowelCount)++;
        }
        else{
            (*consonantCount)++;
        }
    }
}

int main(){
    char str[100];
    int vowelCount;
    int consonantCount;

    printf("Input a String: ");
    gets(str);

    counter(str, &vowelCount, &consonantCount);

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d", consonantCount);

    return 0;
}

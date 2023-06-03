#include <stdio.h>
#include <ctype.h>


int main (){

    char str [80];
    char *letter = NULL;

    printf("\nEnter a string in UPPER CASE: ");
    gets(str);

    letter = str;

    printf("\nString in lower case: ");
    while(*letter){
        printf("%c", tolower(*letter++));
    }

    return 0;
}
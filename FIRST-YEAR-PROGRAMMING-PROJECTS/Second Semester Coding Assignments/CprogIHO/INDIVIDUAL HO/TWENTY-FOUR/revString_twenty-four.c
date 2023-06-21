#include <stdio.h>
#include <string.h>

int main()
{
    char *string = "w3resource";

    for (int i = strlen(string) - 1; i >= 0; i--)
        printf("%c", *(string + i));
}
#include <stdio.h>



int main(){

    FILE* fptr;
    char content[10000];

    fptr = fopen("text.txt", "r");
    while(fgets(content,1000,fptr))  /* This while loop will print all the contents of the text file and will
                                        only continue to print the content if the content array is not yet 
                                        exhausted
                                    */
        printf("%s", content);

    fclose(fptr);

    return 0;
}
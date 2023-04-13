#include <stdio.h>
#include <conio.h>

void main(){
int a, b = 0;

static int c [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

for(a=0; a<10; a++){
    if(a % 2 == 0){
        b += c[a];
    printf("%d c[%d] = %d\n", b, a, c[a]);
    }
}
getch();
}
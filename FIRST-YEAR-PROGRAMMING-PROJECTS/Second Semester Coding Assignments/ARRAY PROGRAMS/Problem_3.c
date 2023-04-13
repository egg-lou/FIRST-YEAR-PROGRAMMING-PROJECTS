#include <stdio.h>
#include <conio.h>

#define r 3
#define c 4

int z[r][c] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

void outing(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
        printf("%d ", z[i][j]);
        printf("\n");
        
    }
}


/*int main(){
    int a, b, val, min = 999;

    outing();

    printf("\n");

    for(a=0; a<r; a++){
        for(b=0; b<c; ++b){
            if(z[a][b] < min){
                min = z[a][b];
            }
            printf("%d ", min);
            min = 999;
        }
        printf("\n");
    }
    getch();
    return 0;
}*/

int main(){
    int a, b, min = 999;

    
    for(a=0; a<r; a++){
        for(b=0; b<c; ++b){
            if(z[a][b] < min){
                 c= z[a][b];
            }
        }
    }
    printf("%d", );
    getch();
    return 0;
}
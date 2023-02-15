#include <stdio.h>
#include <stdlib.h>

void ligarLinhas(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sIncrementoX = 0;
    int sIncrementoY = 0;
    int erro = (2*dy) - dx;
    int x = x0;
    int y = y0;

    if (x1 > x0){
        sIncrementoX = 1;
    }
    if (x1 <= x0)
    {
        sIncrementoX = -1;
    }

    if(y1 > y0){
        sIncrementoY = 1;
    }
    if (y1 <= y0)
    {
        sIncrementoY = -1;
    }

    while( x != x1 && y != y1){
        printf("(%d,%d)\n", x, y);

        if(erro < 0){
            erro = erro + 2 * dy;
            x = x + sIncrementoX;
        }

        else{
            erro = erro + (2 * dy) - ( 2 * dx );
            y = y + sIncrementoY;
            x = x + sIncrementoX;
        }
    }
    printf("(%d,%d)\n", x, y);
}

int main(){
    ligarLinhas(1,1,8,5);
    return 0;
}

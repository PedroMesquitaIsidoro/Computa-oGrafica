#include <stdio.h>
#include <stdlib.h>

void ligarLinhas(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sIncrementoX = 0;
    int sIncrementoY = 0;
    int erro = dx - dy;
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

    while( x != x1 || y != y1){
        printf("(%d,%d)\n", x, y);
        int erro2 = 2 * erro;

        if(erro2 > -dy){
            erro = erro - dy;
            x = x + sIncrementoX;
        }

        if( erro2 < dx){
            erro = erro + dx;
            y = y + sIncrementoY;
        }
    }
    printf("(%d,%d)\n", x, y);
}

int main(){
    ligarLinhas(1,1,8,5);
    return 0;
}
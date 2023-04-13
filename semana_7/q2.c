#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ePrimo(int n ,int nn, int divs);

int main(){
    int n, numero, divs = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &numero);
        if(ePrimo(sqrt(numero), 1, divs))
            printf("Prime\n");
        else
            printf("Not Prime\n");
        divs= 0;
    }
    return 0;
}

int ePrimo(int numero){
    if (nn > n)
        return n;
    if (n % nn == 0)
        divs++;
    ePrimo(n, nn + 1, divs);
    printf("2:%d\n", divs);
    if (divs <= 2)
        return 1;
    return 0;
}
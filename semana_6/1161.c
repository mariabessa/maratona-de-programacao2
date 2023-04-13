#include <stdio.h>


long double falorial(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }else{
        return n * falorial(n-1);
    }
}

int main(){
    int n, m;
    long double soma;
    while(scanf("%d %d", &n, &m) != EOF){
        soma = falorial(n);
        soma+= falorial(m);
        printf("%.0Lf\n", soma);
        soma = 0;
    }
    return 0;
}
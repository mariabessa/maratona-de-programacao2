#include <stdio.h>

int fibonacci(int numero,int *contador){
    (*contador)++;
    if(numero == 1){
        return 1;
    }else if(numero == 0){
        return 0;
    }else{
        return fibonacci(numero-1, contador) + fibonacci(numero-2, contador);
    }
}

int main(){
    int contador = 0, n, numero, resultado;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){{
        scanf("%d", &numero);
        resultado = fibonacci(numero, &contador);
        printf("fib(%d) = %d calls = %d\n", numero, contador - 1, resultado);
        contador = 0;
    }}
}
#include <stdio.h>
#include <stdlib.h>

int mdc(int num1, int num2) {
    int resto;
    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;
    } while (resto != 0);

    return abs(num1);
}

int main(){
    int n, n1, n2, d1, d2, r1, r2, nmdc;
    char op, barra;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %c %d %c %d %c %d", &n1, &barra, &d1, &op, &n2, &barra, &d2);
        switch (op)
        {
            case '+':
                r1 = (n1 * d2) + (n2 * d1);
                r2 = d1 * d2;
            break;
            case '-':
                r1 = n1 * d2 - n2 * d1;
                r2 = d1 * d2;
            break;
            case '*':
                r1 = n1 * n2;
                r2 = d1 * d2;
            break;        
            default:
                r1 = n1 * d2;
                r2 = n2 * d1;
                break;
        }
        nmdc = mdc(r1, r2);
        printf("%d/%d = %d/%d\n", r1, r2, r1/nmdc, r2/nmdc);
    }
}
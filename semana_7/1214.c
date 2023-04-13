#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, tA;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tA);
        int contador = 0;
        double soma = 0;
        double *notas = malloc(sizeof(double) * tA);
        for (int j = 0; j < tA; j++)
        {
            scanf("%lf", &notas[j]);
            soma += notas[j];
        }
        for (int j = 0; j < tA; j++)
        {
            if (notas[j] > soma / (double)tA)
            {
                contador++;
            }
        }
        printf("%.3lf%%\n", ((double)contador / tA) * 100);
        free(notas);
    }
    return 0;
}
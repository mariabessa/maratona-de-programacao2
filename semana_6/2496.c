#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, trocas = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, trocas = 0;
        scanf("%d", &n);
        int *vet = malloc(sizeof(int) * n+1);
        int *pos = malloc(sizeof(int) * n+1);
        char temp[28];
        scanf("%s", temp);
        for(int j = 0; j < n; j++){
            vet[j] = temp[j] - 65;
            pos[temp[j]-65] = j;
        }
        
        for (int k = 0; k < n; k++)
        {
            if(vet[k] != k){
                vet[pos[k]] = vet[k];
                pos[vet[k]] = pos[k];
                vet[k] = k;
                pos[k] = k;
                trocas++;
            }
        }
        if (trocas == 1){
            printf("There are the chance.\n");
        }else
            printf("There aren't the chance.\n");
        trocas = 0;
        
    }
    return 0;
}
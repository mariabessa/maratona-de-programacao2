#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int poder;
    int estavivo;
}Guerreiro;

void merge(Guerreiro *v, int l, int m, int r);

void mergeSort(Guerreiro *v, int l, int r);

int main(){

    int n;
    scanf("%d", &n);

    Guerreiro * quadradonia = malloc(sizeof(Guerreiro) * n);
    Guerreiro * noglonia = malloc(sizeof(Guerreiro) * n);

    
    for(int i = 0; i<n; i++){
        scanf("%d", &quadradonia[i].poder);
        quadradonia[i].estavivo = 1;
    }

   
    for(int i = 0; i<n; i++){
        scanf("%d", &noglonia[i].poder);
        noglonia[i].estavivo = 1;
    }

    mergeSort(noglonia, 0, n-1);
    mergeSort(quadradonia, 0, n-1);

    int numVitorias = 0;
    int i = 0;
   
    for(int j = 0; j < n; j++){
        if(noglonia[i].poder > quadradonia[j].poder){
            numVitorias++;
            i++;
        }
    }

    printf("%d\n", numVitorias);
    return 0;
}
void merge(Guerreiro *v, int l, int m, int r){
    int tamL = (m-l+1);
    int tamR = (r-m);

    Guerreiro *vetL = malloc(tamL * sizeof(Guerreiro));
    Guerreiro *vetR = malloc(tamR * sizeof(Guerreiro));
    int i, j;

    for ( i = 0; i < tamL; i++)
        vetL[i] = v[i + l];

    for(j = 0; j < tamR; j++)
        vetR[j] = v[m + j + 1];
    
    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
        if(i == tamL)
            v[k] = vetR[j++];

        else if(j == tamR)
            v[k] = vetL[i++];

        else if(vetL[i].poder > vetR[j].poder)
            v[k] = vetL[i++];

        else
            v[k] = vetR[j++];
    }
    
    free(vetL);
    free(vetR);
}

void mergeSort(Guerreiro *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}
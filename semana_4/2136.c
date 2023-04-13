#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TAM 100

typedef struct{
    char nome[MAX_TAM];
    int numLetras;
}Candidatos;

void mergeSort(Candidatos *, int, int);
void merge(Candidatos*, int, int, int);
Candidatos *copy(Candidatos *candidatos, int tamanho, int n);


int main(){
    char nomeTemp[MAX_TAM], ehAmigo[4];
    Candidatos *amigos = malloc(sizeof(Candidatos) * 0);
    Candidatos *naoAmigos = malloc(sizeof(Candidatos) * 0);
    int contadorAmigos = 0, contadorNaoAmigos = 0;
    scanf("%s", nomeTemp);
    while(strcmp(nomeTemp, "FIM")){
        scanf("%s", ehAmigo);
        if(!strcmp(ehAmigo, "YES")){
            amigos = realloc(amigos, (contadorAmigos+1) * sizeof(Candidatos));;
            strcpy(amigos[contadorAmigos].nome, nomeTemp);
            amigos[contadorAmigos++].numLetras = strlen(nomeTemp) - 1;
        }else{
            naoAmigos = realloc(naoAmigos, (contadorNaoAmigos+1) * sizeof(Candidatos));
            strcpy(naoAmigos[contadorNaoAmigos].nome, nomeTemp);
            naoAmigos[contadorNaoAmigos++].numLetras = strlen(nomeTemp) - 1;
        }
        scanf("%s", nomeTemp);
    }
    int max = 0;
    for(int i=1; i < contadorAmigos; i++){
        if(amigos[i].numLetras > amigos[max].numLetras){
            max = i;
        }
    }char ganhador[MAX_TAM];
    
    strcpy(ganhador, amigos[max].nome);
    mergeSort(amigos, 0, contadorAmigos-1);
    mergeSort(naoAmigos, 0, contadorNaoAmigos-1);
    for (int i = 0; i < contadorAmigos; i++){
        if (strcmp(amigos[i].nome, amigos[i+1].nome) == 0){
            continue;
        }
        
        printf("%s\n", amigos[i].nome);
    }
    for (int i = 0; i < contadorNaoAmigos; i++){
        printf("%s\n", naoAmigos[i].nome);
    }printf("\n");
    printf("Amigo do Habay:\n%s\n", ganhador);
    return 0;
}

void mergeSort(Candidatos *candidatos, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(candidatos, l, m);
        mergeSort(candidatos, m+1, r);
        merge(candidatos, l, r, m);
    }
}

void merge(Candidatos *candidatos, int l, int r, int m){
    int tam_l= m - l + 1;
    int tam_r = r - m;
    Candidatos *vL = copy(candidatos, tam_l, l);
    Candidatos *vR = copy(candidatos, tam_r, m+1);
    int i = 0, j = 0, k;
    for(k=l; k<=r; k++){
        if(i==tam_l){
            candidatos[k] = vR[j++];  
        }else if(j==tam_r){
            candidatos[k] = vL[i++]; 
        }else if(strcmp(vL[i].nome, vR[j].nome) < 0){
            candidatos[k] = vL[i++]; 
        }else{
            candidatos[k] = vR[j++]; 
        }
    }
    free(vR);
    free(vL);
}

Candidatos *copy(Candidatos *candidatos, int tamanho, int n){
    Candidatos *aux = malloc(sizeof(Candidatos) * tamanho);
    for (int i = 0; i < tamanho; i++){ 
        aux[i] = candidatos[i+n]; 
    }
    return aux;
}
#include <stdio.h>
#include <stdlib.h>

int *copy(int *vetor, int tamanho, int n);
void mergeSort(int *vetor, int l, int r);
void merge( int *vetor, int l, int r, int m);

void mergeSort(int *vetor, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);
        merge(vetor, l, r, m);
    }
}

void merge( int *vetor, int l, int r, int m){
    int j = 0, i = 0;
    int tam_l = m - l + 1, tam_r = r - m;
    int *vl = copy(vetor, tam_l, l);
    int *vr = copy(vetor, tam_r, m+1);
    for(int k = l; k <= r; k++){
        if(i == tam_l){
            vetor[k]= vr[j++];
        }else if(j== tam_r){
            vetor[k] = vl[i++];
        }else if(vl[i] < vr[j]){
            vetor[k] = vl[i++];
        }else{
            vetor[k] = vr[j++];
        }
    }
    free(vl);
    free(vr);
}

int *copy(int *vetor, int tamanho, int n){
    int *v = malloc (tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++){
        v[i] = vetor[i+n];
    }
    return v;
}

int main(){
    int n, num, qntPar = 0, qntImpar = 0;
    scanf("%d", &n);
    int *vp = malloc(sizeof(int)*n);
    int *vi = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if ((num % 2) == 0){
            vp[qntPar] = num;
            qntPar++;
        }else{
            vi[qntImpar] = num;
            qntImpar++;
        }
    }
    mergeSort(vp, 0, qntPar-1);
    mergeSort(vi, 0, qntImpar-1);
    for(int i = 0; i < qntPar; i++){
        printf("%d\n", vp[i]);
    }
    for(int i = qntImpar - 1; i >= 0; i--){
        printf("%d\n", vi[i]);
    }
    free(vi);
    free(vp);
}
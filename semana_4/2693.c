#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char regiao;
    int distancia;
}Aluno;

int compare(Aluno aluno1,Aluno aluno2){
    if(aluno1.distancia < aluno2.distancia){
        return 1;
    }else if(aluno1.distancia > aluno2.distancia){
        return 2;
    }else{
        if(aluno1.regiao < aluno2.regiao){
            return 1;
        }else if(aluno1.regiao > aluno2.regiao){
            return 2;
        }else{
            if(strcmp(aluno1.nome,aluno2.nome) < 0){
                return 1;
            }else if(strcmp(aluno1.nome,aluno2.nome) > 0){
                return 2;
            }
        }
    }

    return 0;
}






void positionChanged(Aluno *arr, int *i, int *j){
    Aluno aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(Aluno *arr, int begin, int end){
    int i,j;
    Aluno pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(compare(arr[i],pivot) == 1 && i < end){
            i++;
        }
        while(compare(arr[j],pivot) == 2 && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(arr,&i,&j);
        }
    }

    if(j > begin){
        quicksort(arr,begin,j);
    }

    if(i < end){
        quicksort(arr, i, end);
    }
}






 
int main(){
 
    Aluno *alunos;
    int cases;
    
    while(scanf("%d",&cases) != EOF){
        alunos = (Aluno*)malloc(cases * sizeof(Aluno));
        for(int i = 0; i < cases; i++){
            scanf("%s",alunos[i].nome);

            getchar();
            scanf("%c",&alunos[i].regiao);

            getchar();
            scanf("%d",&alunos[i].distancia);

            getchar();
        }

        quicksort(alunos,0,cases - 1);

        for(int j = 0; j < cases; j++){
            printf("%s\n",alunos[j].nome);
        }

        free(alunos);
    }
 
    return 0;
}
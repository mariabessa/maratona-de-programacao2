#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 1000000

typedef struct celula{
    struct celula * proxima;
    int diversao;
}Celula;

typedef struct{
    Celula * primeiro;
    int min;
}Pilha;

void IniciaPilha(Pilha * pilha){
    pilha->primeiro = malloc(sizeof(Celula));
    pilha->primeiro->proxima = NULL;
}

int pilhaEhVazia(Pilha * pilha){
    return (pilha->primeiro->proxima == NULL);
}

void push(Pilha * pilha, int diversao){
    Celula *nova = malloc(sizeof(Celula));
    if(nova == NULL) return;
    nova->diversao = diversao;
    nova->proxima = pilha->primeiro->proxima;
    pilha->primeiro->proxima = nova;
}

int pop(Pilha *pilha){
    if(pilhaEhVazia(pilha)) return 0;
    Celula * aux = pilha->primeiro->proxima;
    pilha->primeiro->proxima = aux->proxima;
    free(aux);
    return 1;
}

void pilhaLibera(Pilha * pilha){
    Celula * atual = pilha -> primeiro;
    Celula * proximo = atual->proxima;
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> proxima;
    }
    free(atual);

}

int menosDivertido(Pilha * pilha){
    if(pilhaEhVazia(pilha)) return -1;
    int menosDivertido = 1000000000;
    Celula * atual = pilha->primeiro->proxima;
    while(atual != NULL){
        if(atual->diversao < menosDivertido){
            menosDivertido = atual->diversao;
        }
        atual = atual->proxima;
    }
    return menosDivertido;
}

int main(){
    int n, diversao, min;
    Pilha pilha;
    IniciaPilha(&pilha);
    char comando[MAXTAM];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", comando);
        if(!strcmp("MIN", comando)){
            if(pilhaEhVazia(&pilha)){
                printf("EMPTY\n");
            }else{
                min = menosDivertido(&pilha);
                printf("%d\n", min);
            }
        }else if(!strcmp("POP", comando)){
            if(pilhaEhVazia(&pilha)){
                printf("EMPTY\n");
            }else
                pop(&pilha);
        }else{
            scanf("%d", &diversao);
            push(&pilha, diversao);
        }
    }
    pilhaLibera(&pilha);
    return 0;
}
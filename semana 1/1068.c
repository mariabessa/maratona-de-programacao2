#include <stdio.h>
#include <string.h>
#define MAX_TAM 100000


int main(){
    char string[MAX_TAM];
    int cont1, cont2;
    while(fgets(string, MAX_TAM, stdin) != NULL){
        int tamString = strlen(string);
        string[tamString-1] = '\0';        
        tamString--;
        for (int i = 0; i < tamString; i++){
            if (string[i] == '('){
                cont1++;
            }
            else if(string[i] == ')'){
                cont2++;
                if (cont2 > cont1){
                    cont2++;
                }
            }
        }
        if (cont1 == cont2){
            printf("correct\n");
            
        }else{
            printf("incorrect\n");
        }
        cont1= 0;
        cont2=0;
    }
    return 0;
}
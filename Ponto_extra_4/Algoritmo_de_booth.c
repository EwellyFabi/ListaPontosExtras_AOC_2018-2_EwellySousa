#include <stdio.h>
#include "stdlib.h"
#define BIT 11

void desloca(int* P[BIT]){
    int i;
    for(i=BIT-1; i>0; i--){
        P[i] = P[i-1];
    }
}

void adiciona(int P[BIT], int vet[BIT]){
    int i, resto = 0;
    int soma;
    for(i=BIT-1; i>=0; i--){
        soma = P[i] + vet[i] + resto;
        if(soma == 3){
            P[i] = 1;
            resto = 1;
        } else if(soma == 2){
            P[i] = 0;
            resto = 1;
        } else {
            P[i] = soma;
            resto = 0;
        }
    }
}


void booth(int x, int y){
    int A[BIT] = {0};
    int S[BIT] = {0};
    int P[BIT] = {0};
    int resto;
    int i;

    //Converter x pra binário
    for(i=(BIT/2)-1; (i>=0) || (x = 0); i--){
        resto = x%2;
        A[i] = resto;
        x = x/2;
    }
    resto = 0;
    //Salvando em S o complemento a 2 de A
    for(i=(BIT/2)-1; (i>=0); i--){
        if(i == (BIT/2)-1 && A[i] == 1){
            S[i] = 1;
            resto = 0;
        }else if(i == (BIT/2)-1 && A[i] == 0){
            S[i] = 0;
            resto = 1;
        }else if(A[i] == 1 && resto == 1){
            S[i] = 1;
            resto = 0;
        }else if(A[i] == 1 && resto == 0){
            S[i] = 0;
            resto = 0;
        }else if(A[i] == 0 && resto == 1){
            S[i] = 0;
            resto = 1;
        }else if(A[i] == 0 && resto == 0){
            S[i] = 1;
            resto = 0;
        }

    }

    //Converter y pra binário
    for(i=BIT-2; (i>=(BIT/2)) || (y = 0); i--){
        resto = y%2;
        P[i] = resto;
        y = y/2;
    }

    for(i=0; i<4; i++){
        if(P[BIT-2] == P[BIT-1]){
            desloca(P);
        } else if(P[BIT-2] == 0 && P[BIT-1] == 1){
            adiciona(P,A);
            desloca(P);
        }else if(P[BIT-2] == 1 && P[BIT-1] == 0){
            adiciona(P,S);
            desloca(P);
        }
    }
    /*
    // imprimir vetores
    for(int j2=0; j<9; j++){
        printf("A%d: %d\t",i, A[j]);
        printf("S%d: %d\t",i, S[j]);
        printf("P%d: %d\t",i, P[j]);
        printf("\n");
    }
    */
    printf("Resultado:");
    // imprimir vetores
    for(int i=(BIT/2)-1; i<BIT-2; i++){
        printf("%d", P[i]);
    }
    printf("\n");
}

int main(){
    int multiplicando = 0;
    int multiplicador = 0;

    while(1){
        printf("Digite o valor do multiplicando e do multiplicador: ");
        scanf("%d %d", &multiplicando, &multiplicador);

        if((multiplicando == 0) && (multiplicador == 0)){
            printf("Bye Bye ;* \n");
            system("pause");
            return 0;
        }

        booth(multiplicando, multiplicador);
    }

    return 0;
}

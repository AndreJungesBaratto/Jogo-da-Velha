#include <stdio.h>
#include <conio.h>

#define LIN 3
#define COL 3

void main(){
    int jogo[LIN][COL];

    printf("Bem vindo ao Jogo da Velha! \nPara jogar, digite qual o simbolo que deseja jogar (X ou O) e aperte enter. \n");
    printf("Em seguida, digite a coordenada em que deseja jogar na forma 'linha, coluna'.\n");
    int velha;
    int L, C;
    char simb;

    while(velha==0){

        scanf("%s", &simb);

        if(simb!='x'&&simb!='X'&&simb!='o'&&simb!='O'){
            printf("Digite um simbolo valido!");
            continue;
        }

        scanf("%d, %d", &L, &C);

        if(L>3||C>3){
            printf("Coordenada invalida!");
            continue;
        }

        for(int l=0; l<LIN; l++){
            for(int c=0; c<COL; c++){
                    if(l==L-1&&c==C-1){
                        if(jogo[l][c]=='.'){
                            if(simb=='x'||simb=='X'){
                                printf("|X|");
                                jogo[l][c]='X';
                            }
                            if(simb=='o'||simb=='O'){
                                printf("|O|");
                                jogo[l][c]='O';
                            }
                        }
                        else if(jogo[l][c]!='.'){
                            printf("Essa posicao ja esta ocupada!\n");
                            continue;
                        }
                    }
                    else{
                        if(jogo[l][c]=='X'){
                            printf("|X|");
                        }
                        else if(jogo[l][c]=='O'){
                            printf("|O|");
                        }
                        else {
                            printf("|_|");
                        }
                    }
            }
            printf("\n");

        }
}
}

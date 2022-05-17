#include <stdio.h>
//a função teste irá averiguar se houve vencedor
int teste(int jogo[3][3]){
    for(int l=0; l<3; l++){
        if(jogo[l][0]==jogo[l][1]&&jogo[l][1]==jogo[l][2]&&jogo[l][0]!='.'){
            return 2;
        }
        else continue;
    }

    for(int c=0;c<3;c++){
        if(jogo[0][c]==jogo[1][c]&&jogo[1][c]==jogo[2][c]&&jogo[0][c]!='.'){
            return 2;
        }
        else continue;
    }

    if(jogo[0][0]==jogo[1][1]&&jogo[1][1]==jogo[2][2]&&jogo[0][0]!='.'){
        return 2;
    }
    if(jogo[0][2]==jogo[1][1]&&jogo[1][1]==jogo[2][0]&&jogo[0][2]!='.'){
        return 2;
    }

    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            if(jogo[l][c]=='.'){
                return 1;
                break;
            }
        }
    }
}

void main(){

    int jogo[3][3];

    printf("Bem vind@s ao Jogo da Velha! \nPara jogar, digite qual o simbolo que ira comecar o jogo (X ou O) e aperte enter. \n");
    printf("Em seguida, cada jogador digitara as coordenadas em que deseja jogar na forma 'linha (enter) coluna (enter)'\n");

    int L, C, velha=1;
    char simb;


    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            jogo[l][c]='.';
        }
    }

    scanf("%s", &simb);
        while(simb!='X'&&simb!='x'&&simb!='o'&&simb!='O'){
            printf("Digite um simbolo valido!\n");
            scanf("%s", &simb);
        }
        if(simb=='x')simb='X';
        if(simb=='o')simb='O';

    while(velha==1){
        printf("\nVez de %c!\n", simb);
        scanf("%d", &L);
        scanf("%d", &C);
        if(L>3||C>3){
            printf("Coordenada invalida!\n");
            continue;
        }

        //definir os elementos e imprimir a matriz
        for(int l=0; l<3; l++){
            for(int c=0; c<3; c++){
                    if(l==L-1&&c==C-1){
                        if(jogo[l][c]=='.'){
                            if(simb=='X'){
                                printf("|X|");
                                jogo[l][c]='X';
                            }
                            if(simb=='O'){
                                printf("|O|");
                                jogo[l][c]='O';
                            }
                        }
                        else{
                            printf("Essa posicao ja esta ocupada!\n");
                            if(simb=='X')simb='O';
                            else simb='X';
                            break;
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
        //fim do for
        }
        if(simb=='X')simb='O';
        else simb='X';
        velha=teste(jogo);
    //fim do while
    }
    if(velha!=2){
        printf("Deu velha!");
        }
    else{
        if(simb=='X')simb='O';
        else simb='X';
        printf("Parabens, %c ganhou!", simb);
    }
//fim do void
}

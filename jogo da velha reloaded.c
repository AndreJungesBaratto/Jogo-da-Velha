#include <stdio.h>

int imprimir(int jogo[3][3]){
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            if(jogo[l][c]=='X')printf("|X|");
            if(jogo[l][c]=='O')printf("|O|");
            else printf("|_|");
        }
        printf("\n");
    }
}

int comecar(int jogo[3][3]){
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            jogo[l][c]='.';
        }
    }
    char jogador;
    scanf("%s", &jogador);
    while(jogador!='O'&&jogador!='X'){
        printf("Digite um simbolo válido\n");
        scanf("%s", &jogador);
    }
    imprimir(jogo);
    return jogador;
}

int simbolo(int jogo[3][3]){
    char simbolo, jogador;
    simbolo=jogador;
        if(jogador=='X')jogador='O';
        else jogador='X';
}

int armazenar(int jogo[3][3]){
    int L, C;
    scanf("%c", &L);
    scanf("%c", &C);
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            if(l==L&&c==C){
                if(simbolo=='X')jogo[l][c]='X';
                if(simbolo=='O')jogo[l][c]='O';

            }
        }
    }
}

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
    int jogo[3][3], jogador, vez;
    jogador=comecar(jogo);
    while(1){
        armazenar(jogo);
        vez=simbolo(jogo);
        imprimir(jogo);
        return teste(jogo);
    }
}

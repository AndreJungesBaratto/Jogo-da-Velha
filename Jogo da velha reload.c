//Aluno: André Junges Baratto
//NºUSP: 13731107
//Grupo: Apenas eu, mas fui aconselhado e ajudado por dois colegas, que também fizeram sozinho.

//Usaremos a biblioteca
#include <stdio.h>

//A funcao 'imprimir', como o nome diz, serve para imprimir a matriz. Como sua unica funcao eh imprimir, nao ha necessidade de retorno e, logo, usei o void.
//Basicamente ela ira imprimir na matriz os simbolos em suas devidas casas, definidas pelas outras funcoes abaixo. Como sera utilizada por quase todas as funcoes, foi colocada por primeiro no codigo.
void imprimir(int jogo[3][3]){
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            if(jogo[l][c]=='X'){printf("|X|");}
            if(jogo[l][c]=='O'){printf("|O|");}
            if(jogo[l][c]=='.'){printf("|_|");}
        }
        printf("\n");
    }
}

//A funcao 'comecar' serve para inicializar o jogo, definindo todos as coordenadas como vazias e determinando o simbolo inicial.
int comecar(int jogo[3][3]){
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            jogo[l][c]='.';
        }
    }
    char jogador;
    scanf("%s", &jogador);
    if(jogador=='x')jogador='X';
    if(jogador=='o')jogador='O';
    while(jogador!='O'&&jogador!='X'){
        printf("Digite um simbolo valido\n");
        scanf("%s", &jogador);
    }
    imprimir(jogo);
    return jogador;
}

int simbolo(char jogador){
        if(jogador=='X')jogador='O';
        else jogador='X';
        return jogador;
}

int armazenar(int jogo[3][3], char jogador){
    int L, C;
    printf("Vez de %c!\n", jogador);
    scanf("%d", &L);
    scanf("%d", &C);
        while(L>3||C>3){
            printf("Digite uma coordenada valida!\n");
                scanf("%d", &L);
                scanf("%d", &C);
        }
                if(jogo[L-1][C-1]=='.'){
                    if(jogador=='X')jogo[L-1][C-1]='X';
                    if(jogador=='O')jogo[L-1][C-1]='O';
                        imprimir(jogo);
                        jogador=simbolo(jogador);
                }
                else{
                    printf("Essa coordenada ja esta ocupada!\n");
                }
    return jogador;
}

int teste(int jogo[3][3]){
    for(int l=0; l<3; l++){
        if(jogo[l][0]==jogo[l][1]&&jogo[l][1]==jogo[l][2]&&jogo[l][0]!='.'){
            return 2;
        }
    }

    for(int c=0;c<3;c++){
        if(jogo[0][c]==jogo[1][c]&&jogo[1][c]==jogo[2][c]&&jogo[0][c]!='.'){
            return 2;
        }
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
    int jogo[3][3], fim;
    char jogador;
    printf("Bem vindo ao Jogo da Velha!\nPara jogar, escolha um símbolo (X ou O) para começar.\nEm seguida, basta que cada jogador digite as coordenadas me que deseja jogar na forma 'linha (enter) coluna (enter)'.\nBom jogo!\n");
    jogador=comecar(jogo);
    while(1){
        jogador=armazenar(jogo, jogador);
        fim=teste(jogo);
        if(fim==2){
                jogador=simbolo(jogador);
            printf("Parabens, %c ganhou!", jogador);
            break;
        }
        if(fim==1){
            continue;
        }
        else printf("Deu velha!");
    }
}

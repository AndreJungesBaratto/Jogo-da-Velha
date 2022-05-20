//Aluno: Andr� Junges Baratto
//N. USP: 13731107
//Grupo: Apenas eu, mas fui aconselhado e ajudado por dois colegas, que tamb�m fizeram sozinho.

//Usaremos a biblioteca stdio.h para ler e escrever dados.
#include <stdio.h>

//A funcao 'imprimir', como o nome diz, serve para imprimir a matriz. Como sua unica funcao eh imprimir, nao ha necessidade de retorno e, logo, usei o void.
//Basicamente ela ira imprimir na matriz os simbolos em suas devidas casas, definidas pelas outras funcoes abaixo. Como sera utilizada por quase todas as funcoes, foi colocada por primeiro no codigo.
void imprimir(int jogo[3][3]){
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            //Aqui a funcao analisa cada coordenada e imprime o respectivo simbolo na matriz.
            if(jogo[l][c]=='X'){printf("|X|");}
            if(jogo[l][c]=='O'){printf("|O|");}
            if(jogo[l][c]=='.'){printf("|_|");}
        }
        //Ao final da linha, ha uma quebra para a proxima linha.
        printf("\n");
    }
}

//A funcao 'comecar' serve para inicializar o jogo, definindo todos as coordenadas como vazias e determinando o simbolo inicial.
//Como preciso retornar o primeiro jogador, uso o int.
int comecar(int jogo[3][3]){

    //Aqui defino todos os pontos da matriz como vazias
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            //Defino tudo como '.', que na funcao 'imprimir' eh considerado como vazio.
            jogo[l][c]='.';
        }
    }

    //Aqui peço que o usuário informe qual simbolo ira comecar o jogo
    char jogador;
    scanf("%s", &jogador);

    //Essas duas linhas sao apenas para que, caso o usuario entre 'x' ou 'o', o jogo comece mesmo assim. Para que o resto do codigo funcione, converto-os a 'X' e 'O'.
    if(jogador=='x')jogador='X';
    if(jogador=='o')jogador='O';

    //Caso o usuario forneca um simbolo invalido, o jogo pedira que seja inserido um simbolo valido, e repete enquanto nao for inserido um simbolo valido.
    while(jogador!='O'&&jogador!='X'){
        printf("Digite um simbolo valido\n");
        scanf("%s", &jogador);
    }

    //Quando o simbolo eh definido, o jogo comeca. Assim, chamo a funcao 'imprimir'.
    imprimir(jogo);

    //A funcao retornara o jogador que comecou, fazendo com que essa informacao retorne para a funcao principal do jogo, a 'main'.
    return jogador;
}

//A funcao 'simbolo' serve para inverter o jogador da vez. Assim, nao ha necessidade de pedir ao usuario toda vez qual o simbolo que deseja jogar.
//Como preciso retornar o proximo jogador, uso o int.
int simbolo(char jogador){
        if(jogador=='X')jogador='O';
        else jogador='X';
        //Apos a inversao, a funcao retorna o novo jogador para a funcao que lhe chamar.
        return jogador;
}

//A funcao armazenar serve para: 1) pedir a coordenada em que o jogador deseja jogar; 2) redefinir as coordenadas escolhidas pelo jogador para o respectivo simbolo; 3)reimprimir o jogo e inverter o jogador.
//Como preciso retornar o proximo jogador, uso o int.
int armazenar(int jogo[3][3], char jogador){

    //Aqui defino as variaveis para as quais serao atribuidas as coordenadas escolhidas pelo jogador. L sera as linha, C sera a coluna.
    int L, C;

    //Aqui o comando informa qual o jogador da vez.
    printf("Vez de %c!\n", jogador);

    //Aqui, o comando le as coordenadas escolhidas.
    scanf("%d", &L);
    scanf("%d", &C);

        //Caso seja inserida uma coordenada invalida, este while continuara pedindo as coordenadas ate que uma valida seja inserida..
        while(L>3||C>3){
            printf("Digite uma coordenada valida!\n");
                scanf("%d", &L);
                scanf("%d", &C);
        }

                //Aqui, a coordenada escolhida sera redefinida para o simbolo da vez. Como as coordenadas da matriz nos 'for'vai de '0' a '2' e nas coordenadas do jogo vai de '1' a '3', eh preciso subtrair 1 de cada coordenada.
                //Caso a casa esteja vazia, seu simbolo sera redefinido, a matriz sera imprimida e o jogador sera invertido.
                if(jogo[L-1][C-1]=='.'){
                    if(jogador=='X')jogo[L-1][C-1]='X';
                    if(jogador=='O')jogo[L-1][C-1]='O';

                        //Apos redefinir as coordenadas escolhidas, a matriz eh imprimida novamente, e o jogador eh invertido.
                        imprimir(jogo);
                        jogador=simbolo(jogador);
                }

                //Caso a casa escolhida já esteja definida como 'X' ou 'O', o comando nao ira redefinir nada, nao ira imprimir a matriz e o jogador nao sera invertido.
                else{
                    printf("Essa coordenada ja esta ocupada!\n");
                }

    //Ao final do comando, a funcao retorna o jogador, de modo que, caso tenha sido invertido, continuara invertido quando voltar para a funcao 'main'.
    return jogador;
}

//A funcao 'teste' ira verificar se houve vencedor ou se o jogo ainda nao acabou. Caso nao haja vencedor e o jogo ja tenha acabado, significa que deu velha.
//Como preciso retornar o resultado, uso o int.
int teste(int jogo[3][3]){

    //Aqui, o comando ira testar cada linha. Se todos os elementos da linha forem iguais, houve vencedor. Porem, caso todos os elementos da linha estejam vazias, nao houve vencedor, entao devo desconsiderar esse caso.
    for(int l=0; l<3; l++){
        if(jogo[l][0]==jogo[l][1]&&jogo[l][1]==jogo[l][2]&&jogo[l][0]!='.'){
            //Caso for verdade, ira retornar 2, que significa que houve vencedor.
            return 2;
        }
    }

    //Aqui, o comando ira testar cada coluna. Se todos os elementos da coluna forem iguais, tembém houve vencedor. Porem, da mesma forma que na linha, devemos desconsiderar o caso em que todos os elementos sao vazios.
    for(int c=0;c<3;c++){
        if(jogo[0][c]==jogo[1][c]&&jogo[1][c]==jogo[2][c]&&jogo[0][c]!='.'){
            //Caso for verdade, ira retornar 2, que significa que houve vencedor.
            return 2;
        }
    }

    //Aqui, o comando testa as diagonais. Caso os elementos das diagonais sejam iguais, houve vencedor. Tambem eh necessario desconsiderar o caso em que todos os elementos sao vazios.
    //Diagonal principal
    if(jogo[0][0]==jogo[1][1]&&jogo[1][1]==jogo[2][2]&&jogo[0][0]!='.'){
        return 2;
    }

    //Diagonal secundaria.
    if(jogo[0][2]==jogo[1][1]&&jogo[1][1]==jogo[2][0]&&jogo[0][2]!='.'){
        return 2;
    }

    //Caso nao haja vencedor, esse comando ira verificar se ha alguma coordenada vazia na matriz.
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            if(jogo[l][c]=='.'){
                //Caso seja verdadeiro, significa que o jogo ainda nao acabou, retornando, portanto, 1.
                return 1;
                break;
            }
        }
    }
}

//Aqui comeca a funcao principal, em que todas as funcoes sao reunidas para rodas o jogo.
//Como nao ha necessidade de retornar nada, uso o void.
void main(){
    //Aqui defino a matriz do jogo e a int fim que sera usada para testar se o jogo acabou.
    int jogo[3][3], fim;

    //Aqui defino a variavel jogador, que sera usada para armazenar o simbolo correto nas coordenadas.
    char jogador;
        //Texto indrodutorio com instrucoes de como jogar.
        printf("Bem vindo ao Jogo da Velha!\nPara jogar, escolha um simbolo (X ou O) para come�ar.\nEm seguida, basta que cada jogador digite as coordenadas me que deseja jogar na forma 'linha (enter) coluna (enter)'.\n!!Atencao!!: se for inserida uma letra nas coordenadas, o programa ira bugar. Caso ocorra, reinicie o jogo.\nBom jogo!\n");
        //O jogador inicial será definido apos o jgo comecar. Logo, ao mesmo tempo em que redefino o jogador, chamo a funcao que inicia o jogo.
        jogador=comecar(jogo);

        //Aqui, enquanto o 'teste' continuar retornando 1, o jogo ira continuar.
        while(1){
            //O jogador sera redefinido ao final da funcao 'armazenar'. Assim, ao mesmo tempo que redefino o jogador, a funcao 'armazenar' eh chamada.
            jogador=armazenar(jogo, jogador);
            //Apos redefinir as coordenadas, e o jogador na funcao armazenar, basta verificar se o jogo acabou ou nao. Assim, chamo a funcao 'teste'.
            fim=teste(jogo);

            //Caso a funcao 'teste' retorne 2, houve vencedor.
            if(fim==2){
                //Por algum motivo, apos o jogo acabar, o jogador estava invertendo uma ultima vez, dizendo que o jogador que perdeu havia ganhado. Aqui, reinverto o jogador novamente, a fim de informar corretamente o vencedor.
                jogador=simbolo(jogador);
                //Aqui, informo o vencedor.
                printf("Parabens, %c ganhou!", jogador);
                //O while, entao, sera quebrado, encerrando o jogo.
                break;
            }

            //Caso o teste retorne 1, o jogo ainda nao acabou. Logo, o while ira continuar.
            if(fim==1){
               continue;
            }

            //Caso o teste nao retorne nem 1 nem 2, significa que deu velha.
            else{
                //Portanto, o comando informa que deu velha e encerra o while.
                printf("Deu velha!");
                break;
            }
        }
}

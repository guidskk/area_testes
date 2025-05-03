#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // estrutura do jogo 

    int linha, coluna, l, c, jogador, ganhou, jogadas, opcao;
    char tabuleiro[3][3];

    do{
        jogador = 1,
        ganhou = 0;
        jogadas = 0;

        for(linha = 0; linha < 3; linha++){
            for(coluna = 0; coluna < 3; coluna++){
                tabuleiro[linha][coluna] = ' ';
            }
        }
        
        do{
        printf("\n\n\t 0   1   2\n\n");
        for(linha = 0; linha < 3; linha++){
            for(coluna = 0; coluna < 3; coluna++){
                if(coluna == 0){
                printf("\t");
                }
                printf(" %c ", tabuleiro[linha][coluna]);
                if(coluna < 2){
                    printf("|");
                }
                if(coluna == 2){
                    printf("  %d", linha);
                }
                
            }
            if(linha < 2 ){
                printf("\n\t-----------");
            printf("\n");
            }
        }

        // coordenadas

        do{
                printf("\nJogador %d: digite a linha e a coluna para jogar!: ", jogador);
                scanf("%d%d", &l, &c);
            }while(l < 0 || l > 2 || c < 0 || c > 2 || tabuleiro[l][c] != ' ');

            if(jogador == 1){
                tabuleiro[l][c] = 'O';
                jogador++;
            }
            else{
                tabuleiro[l][c] = 'X';
                jogador = 1;
            }
            jogadas++;

            // ganhou por linha

            if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' ||
            tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' ||
            tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
            printf("O jogador 1 venceu por linha!\n");
            ganhou = 1;
            }
            
            if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' ||
            tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' ||
            tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
            printf("O jogador 2 venceu por linha!\n");
            ganhou = 1;
            }

            // ganhou por coluna

            if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' ||
            tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' ||
            tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
            printf("O jogador 1 venceu por coluna!\n");
            ganhou = 1;
            }

            if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' ||
            tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' ||
            tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
            printf("O jogador 2 venceu por coluna!\n");
            ganhou = 1;
            }

            // ganhou por diagonal principal

            if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
                printf("O jogador 1 venceu na diagonal principal!\n");
                ganhou = 1;
            }

            if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
                printf("O jogador 2 venceu na diagonal principal!\n");
                ganhou = 1;
            }

            // ganhou na diagonal secundaria

            if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
            printf("O jogador 1 venceu na diagonal secundaria!\n");
            ganhou = 1;
            }

            if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
                printf("O jogador 2 venceu na diagonal secundaria!\n");
                ganhou = 1;
            }
        } while(ganhou == 0 && jogadas < 9);

          if(ganhou == 0){
            printf("\nDeu velha!\n");
          }
        printf("\nDigite 1 para jogar novamente!");
        scanf("%d", &opcao);
        
    } while(opcao == 1);
    
  return 0;
}
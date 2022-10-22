#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

void marcarJogada1(char ***tabela, int linha, int coluna, int vez)
{
    if (vez % 2 != 0)
    {
        (*tabela)[linha][coluna] = 'X';
    }
    else
    {
        (*tabela)[linha][coluna] = 'O';
    }
}

int realizarJogada1(char ***tabela, int flag)
{
    char comando[10], comando2[20];
    int jogadas;
    int vez = 1;
    Jogador jog1;
    getchar();

    char **tabela2 = criaTabela();
    if (flag == 1)
    {
        printf(BOLD(WHITE("    Digite do nome do jogador 1: ")));
        fgets(jog1.nome, 20, stdin);

        int tam1 = strlen(jog1.nome);
        jog1.nome[tam1 - 1] = '\0';
        jogadas = 0;
        system("clear");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tabela2[i][j] = (*tabela)[i][j];
            }
        }
        jogadas = nroJogadas(tabela2);
    }
    imprimeTabela(tabela2);

    do
    {
        if (vez % 2 != 0)
        {
            printf("\n");
            printf("    %s, digite o comando: ", jog1.nome);
            scanf("%s", comando);

            if (strcmp(comando, "marcar") == 0)
            {
                scanf("%s", comando2);
                int local = atoi(comando2);
                int coluna = (local % 10) - 1;
                int linha = (local / 10) - 1;

                while (checaLocal(tabela2, linha, coluna) == 0)
                {
                    printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog1.nome);
                    scanf("%s%s", comando, comando2);
                    int local = atoi(comando2);
                    coluna = (local % 10) - 1;
                    linha = (local / 10) - 1;
                }
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
                jogadas++;
            }
            else if (strcmp(comando, "voltar") == 0)
            {
                return 0;
            }
            else if (strcmp(comando, "salvar") == 0)
            {
                scanf("%s", comando2);
                salvaJogo(comando2, tabela2);
                printf("\n\n");
            }
            else
            {
                do
                {
                    printf(BOLD(RED("    Comando não encontrado!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog1.nome);
                    scanf("%s", comando);
                } while (strcmp(comando, "marcar") != 0);
                scanf("%s", comando2);
                int local = atoi(comando2);
                int coluna = (local % 10) - 1;
                int linha = (local / 10) - 1;
                marcarJogada2(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
                jogadas++;
            }
        }
        else
        {
            printf("\n");
            printf("    Vez do computador!");
            printf("\n");

            if (vez == 2)
            {
                if (checaLocal(tabela2, 2, 2) == 1)
                {
                    int linha = 2;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                }
                else if (checaLocal(tabela2, 0, 2) == 1)
                {
                    int linha = 0;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                }
            }

            else if (((tabela2[0][0] == 'X' && tabela2[2][2] == 'X') || (tabela2[0][2] == 'X' && tabela2[2][0] == 'X')) && checaLocal(tabela2, 2, 1) == 1)
            {
                int linha = 2;
                int coluna = 1;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][0] == 'X' && tabela2[0][1] == 'X') || (tabela2[0][0] == 'O' && tabela2[0][1] == 'O'))  && checaLocal(tabela2, 0, 2) == 1)
            {
                    int linha = 0;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][0] == 'X' && tabela2[0][2] == 'X') || (tabela2[0][0] == 'O' && tabela2[0][2] == 'O')) && checaLocal(tabela2, 0,1) == 1)
            {
                    int linha = 0;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][1] == 'X' && tabela2[0][2] == 'X') || (tabela2[0][1] == 'O' && tabela2[0][2] == 'O')) && checaLocal(tabela2, 0,0) == 1)
            {
                    int linha = 0;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
            }
            else if (((tabela2[1][0] == 'X' && tabela2[1][1] == 'X') || (tabela2[1][0] == 'O' && tabela2[1][1] == 'O'))  && checaLocal(tabela2, 1,2) == 1)
            {
                    int linha = 1;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[1][0] == 'X' && tabela2[1][2] == 'X') || (tabela2[1][0] == 'O' && tabela2[1][2] == 'O')) && checaLocal(tabela2, 1,1) == 1)
            {
                    int linha = 1;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[1][1] == 'X' && tabela2[1][2] == 'X') || (tabela2[1][1] == 'O' && tabela2[1][2] == 'O'))  && checaLocal(tabela2,  1, 0) == 1)
            {
                    int linha = 1;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[2][0] == 'X' && tabela2[2][1] == 'X') || (tabela2[2][0] == 'O' && tabela2[2][1] == 'O')) && checaLocal(tabela2, 2, 2) == 1)
            {
                    int linha = 2;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if ((tabela2[2][0] == 'O' && tabela2[2][2] == 'O') && checaLocal(tabela2, 2, 1) == 1)
            {
                    int linha = 2;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
            }
            else if (((tabela2[2][1] == 'X' && tabela2[2][2] == 'X') || (tabela2[2][1] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 2,0) == 1)
            {
                    int linha = 2;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
                
            }
            // checa coluna
            else if (((tabela2[0][0] == 'X' && tabela2[1][0] == 'X') || (tabela2[0][0] == 'O' && tabela2[1][0] == 'O')) && checaLocal(tabela2, 2, 0) == 1)
            {
                    int linha = 2;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[1][0] == 'X' && tabela2[2][0] == 'X') || (tabela2[1][0] == 'O' && tabela2[2][0] == 'O')) && checaLocal(tabela2, 0,0) == 1)
            {
                    int linha = 0;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][0] == 'X' && tabela2[2][0] == 'X') || (tabela2[0][0] == 'O' && tabela2[2][0] == 'O')) && checaLocal(tabela2, 1,0) == 1)
            {
                    int linha = 1;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][1] == 'X' && tabela2[1][1] == 'X') || (tabela2[0][1] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 2, 1) == 1)
            {
                    int linha = 2;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[1][1] == 'X' && tabela2[2][1] == 'X') || (tabela2[1][1] == 'O' && tabela2[2][1] == 'O'))  && checaLocal(tabela2, 0, 1) == 1)
            {
                    int linha = 0;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][1] == 'X' && tabela2[2][1] == 'X') || (tabela2[0][1] == 'O' && tabela2[2][1] == 'O')) && checaLocal(tabela2, 1, 1) == 1)
            {
                    int linha = 1;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][2] == 'X' && tabela2[1][2] == 'X') || (tabela2[0][2] == 'O' && tabela2[1][2] == 'O')) && checaLocal(tabela2, 2, 2) == 1)
            {
                    int linha = 2;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
            }
            else if (((tabela2[1][2] == 'X' && tabela2[2][2] == 'X') || (tabela2[1][2] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 0,2) == 1)
            {
                    int linha = 0;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][2] == 'X' && tabela2[2][2] == 'X') || (tabela2[0][2] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 1,2) == 1)
            {
                    int linha = 1;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }

            // checha diagonal principal
            else if (((tabela2[0][0] == 'X' && tabela2[1][1] == 'X') || (tabela2[0][0] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 2, 2) == 1)
            {
                    int linha = 2;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][0] == 'X' && tabela2[2][2] == 'X') || (tabela2[0][0] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 1, 1) == 1)
            {
                    int linha = 1;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[2][2] == 'X' && tabela2[1][1] == 'X') || (tabela2[2][2] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 0,0) == 1)
            {
                    int linha = 0;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }

            // checa diagonal secundaria
            else if (((tabela2[0][2] == 'X' && tabela2[1][1] == 'X') || (tabela2[0][2] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 2, 0) == 1)
            {
                    int linha = 2;
                    int coluna = 0;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[0][2] == 'X' && tabela2[2][0] == 'X') || (tabela2[0][2] == 'O' && tabela2[2][0] == 'O')) && checaLocal(tabela2, 1, 1) == 1)
            {
                    int linha = 1;
                    int coluna = 1;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else if (((tabela2[2][0] == 'X' && tabela2[1][1] == 'X') || (tabela2[2][0] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 0,2) == 1)
            {
                    int linha = 0;
                    int coluna = 2;
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                
            }
            else
            {
                int linha, coluna;
                do
                {
                    srand(time(0));
                    linha = rand() % 3;
                    coluna = rand() % 3;
                } while (checaLocal(tabela2, linha, coluna) != 1);
                    marcarJogada1(&tabela2, linha, coluna, vez);
                    imprimeTabela(tabela2);
                }
            
            jogadas++;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                (*tabela)[i][j] = tabela2[i][j];
            }
        }
        vez++;

    } while (jogadas < 9 && checaFim(tabela2) == 0);

    char carac;

    if (checaFim(tabela2) == 1)
    {
        printf("\n    Parabéns" BOLD(GREEN(" %s")) ", voce ganhou!", jog1.nome);
        printf(BOLD(YELLOW("\n    Digite qualquer tecla para continuar: ")));
        scanf("%c", &carac);
        printf("\n\n");
    }
    else if (checaFim(tabela2) == 2)
    {
        printf("\n    Ganhei!");
        printf(BOLD(YELLOW("\n    Digite qualquer tecla para continuar: ")));
        scanf("%c", &carac);
        printf("\n\n");
    }
    else
    {
        printf("\n    Deu velha!\n\n");
        printf(BOLD(YELLOW("\n    Digite qualquer tecla para continuar: ")));
        scanf("%c", &carac);
        printf("\n\n");
    }

    liberaTabela(tabela2);
    liberaTabela2(tabela);
    return 0;
}
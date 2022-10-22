#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

void marcarJogada2(char ***tabela, int linha, int coluna, int vez)
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

int realizarJogada2(char ***tabela, int flag)
{ // faz jogadas com 2 jogadores
    system("clear");
    printf(BOLD(BLUE("    Durante o jogo digite \"voltar\" para retornar ao menu\n\n")));
    char comando[10], comando2[20];
    Jogador jog1, jog2;
    int jogadas;
    int vez = 1;
    

    char **tabela2 = criaTabela();
    if (flag == 1)
    {
        getchar();
        printf(BOLD(WHITE("    Digite do nome do jogador 1: ")));
        fgets(jog1.nome, 20, stdin);
        printf(BOLD(WHITE("    Digite do nome do jogador 2: ")));
        fgets(jog2.nome, 20, stdin);

        if (strcmp(jog1.nome,jog2.nome)==0)
        {
            do
            {
                printf(BOLD(RED("\n    Nome inválido! Os dois jogadores não podem ter nomes iguais!")));
                printf(BOLD("\n    Digite o nome do jogador 2: "));
                fgets(jog2.nome, 20, stdin);
            } while (strcmp(jog1.nome,jog2.nome)==0);
            
        }
        int tam1 = strlen(jog1.nome);
        int tam2 = strlen(jog2.nome);
        jog1.nome[tam1 - 1] = '\0';
        jog2.nome[tam2 - 1] = '\0';
        jogadas = 0;
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
    system("clear");
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
                marcarJogada2(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
                jogadas++;
            }
            else if (strcmp(comando, "voltar") == 0)
            {
                return 0;
            } else if (strcmp(comando, "salvar") == 0)
            {
                scanf("%s", comando2);
                salvaJogo(comando2, tabela2);
                printf("\n\n");
                return 0;
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
            printf("    %s digite o comando: ", jog2.nome);
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
                marcarJogada2(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
                jogadas++;
            }
            else if (strcmp(comando, "voltar") == 0)
            {
                printf("\n");
                return 0;
            } else if (strcmp(comando, "salvar") == 0)
            {
                scanf("%s", comando2);
                salvaJogo(comando2, tabela2);
                printf("\n\n");
                return 0;
            }
            else
            {
                do
                {
                    printf(BOLD(RED("    Comando não encontrado!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog2.nome);
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

            
        } for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    (*tabela)[i][j] = tabela2[i][j];
                }
            }

        vez++;

    } while (checaFim(tabela2) == 0 && jogadas < 9);

    char carac;

    if (checaFim(tabela2) == 1)
    {
        printf("\n    Parabéns " BOLD(GREEN("%s")) ", voce ganhou!", jog1.nome);
        
        printf(BOLD(YELLOW("\n    Digite qualquer tecla para continuar: ")));
        scanf("%c", &carac);
        printf("\n\n");
    }
    else if (checaFim(tabela2) == 2)
    {
        printf("\n    Parabéns " BOLD(GREEN(" %s")) ", voce ganhou!", jog2.nome);

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




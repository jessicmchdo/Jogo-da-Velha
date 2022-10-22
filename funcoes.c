#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

void menu()
{
    int op1, op2;

    char **tabela = criaTabela();
    Info info;

    do
    {
        printf("\n\n");
        printf(BOLD("    0. Sair do Jogo\n"));
        printf(BOLD("    1. Começar um novo jogo\n"));
        printf(BOLD("    2. Continuar um jogo salvo\n"));
        printf(BOLD("    3. Continuar o jogo atual\n"));
        printf(BOLD("    4. Exibir o ranking\n"));
        printf(BOLD("    Durante o jogo digite \"voltar\" para retornar ao menu\n\n"));
        printf(BOLD("    Escolha a opção: "));

        scanf("%d", &op1);
        switch (op1)
        {
        case 1: // novo jogo
            printf(BOLD("    Digite o número de jogadores (1 ou 2): "));
            scanf("%d", &op2);
            switch (op2)
            {
            case 1: // player vs pc
                realizarJogada1(&tabela, 1);
                info.continua = true;
                info.jogada = 1;
                break;
            case 2: // player vs player
                realizarJogada2(&tabela, 1);
                info.continua = true;
                info.jogada = 2;
                break;
            default:
                printf(BOLD(RED("    Opção inválida\n\n")));
                break;
            }
            break;

        case 0:
            op1 = 1;
            return;
        case 4: // mostra ranking
            //mostrarRanking();
            break;
        case 3: // continua jogo atual
            if (info.continua == true)
            {
                if (info.jogada == 2)
                {
                    realizarJogada2(&tabela, 5);
                }
                else
                {
                    realizarJogada1(&tabela, 5);
                }
            }

            break;
        default:
            printf(BOLD(RED("    Opção inválida")));
            break;
        }
    } while ((op1 != 0) || (op1 > 4));
    return;
}

char **criaTabela()
{
    char **tabela;
    // alocar
    tabela = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        tabela[i] = malloc(n * sizeof(char));
    }

    // inicializar com espaço em branco
    for (int linha = 0; linha < n; linha++)
    {
        for (int coluna = 0; coluna < n; coluna++)
        {
            tabela[linha][coluna] = ' ';
        }
    }
    return tabela;
}

void liberaTabela(char **tabela)
{
    for (int i = 0; i < n; i++)
    {
        free(tabela[i]);
    }
    free(tabela);
}

void liberaTabela2(char ***tabela)
{
    for (int i = 0; i < n; i++)
    {
        free(*tabela[i]);
    }
    free(*tabela);
}

void limpaTabela(char ***tabela)
{
    // inicializar com espaço em branco
    for (int linha = 0; linha < n; linha++)
    {
        for (int coluna = 0; coluna < n; coluna++)
        {
            (*tabela)[linha][coluna] = ' ';
        }
    }
}

void imprimeTabela(char **tabela)
{
    printf("\n\n\t 1   2   3\n\n");
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (coluna == 0)
                printf("\t");
            printf(" %c ", tabela[linha][coluna]);
            if (coluna < 2)
                printf("|");

            if (coluna == 2)
            {
                printf("     %d", linha + 1);
            }
        }
        printf("\n");
        if (linha < 2)
            printf("\t-----------\n");
        // printf("\n");
    }
}

int checaLocal(char **tabela, int linha, int coluna)
{
    if (linha < n && coluna < n)
    {
        if (tabela[linha][coluna] == ' ')
        {
            return 1;
        }
    }

    return 0;
}

int checaLinha(char **tabela)
{
    if ((tabela[0][0] == 'X' && tabela[0][1] == 'X' && tabela[0][2] == 'X') ||
        (tabela[1][0] == 'X' && tabela[1][1] == 'X' && tabela[1][2] == 'X') ||
        (tabela[2][0] == 'X' && tabela[2][1] == 'X' && tabela[2][2] == 'X'))
    {
        return 1;
    }
    else if ((tabela[0][0] == 'O' && tabela[0][1] == 'O' && tabela[0][2] == 'O') ||
             (tabela[1][0] == 'O' && tabela[1][1] == 'O' && tabela[1][2] == 'O') ||
             (tabela[2][0] == 'O' && tabela[2][1] == 'O' && tabela[2][2] == 'O'))
    {
        return 2;
    }

    return 0;
}

int checaColuna(char **tabela)
{
    if ((tabela[0][0] == 'O' && tabela[1][0] == 'O' && tabela[2][0] == 'O') ||
        (tabela[0][1] == 'O' && tabela[1][1] == 'O' && tabela[2][1] == 'O') ||
        (tabela[0][2] == 'O' && tabela[1][2] == 'O' && tabela[2][2] == 'O'))
    {
        return 2;
    }
    else if ((tabela[0][0] == 'X' && tabela[1][0] == 'X' && tabela[2][0] == 'X') ||
             (tabela[0][1] == 'X' && tabela[1][1] == 'X' && tabela[2][1] == 'X') ||
             (tabela[0][2] == 'X' && tabela[1][2] == 'X' && tabela[2][2] == 'X'))
    {
        return 1;
    }

    return 0;
}

int checaDiagonalPrincipal(char **tabela)
{
    if (tabela[0][0] == 'O' && tabela[1][1] == 'O' && tabela[2][2] == 'O')
    {
        return 2;
    }
    else if (tabela[0][0] == 'X' && tabela[1][1] == 'X' && tabela[2][2] == 'X')
    {
        return 1;
    }

    return 0;
}

int checaDiagonalSecundaria(char **tabela)
{
    if (((tabela[0][2] == 'O') && (tabela[1][1] == 'O') && (tabela[2][0] == 'O')))
    {
        return 2;
    }
    else if (((tabela[0][2] == 'X') && (tabela[1][1] == 'X') && (tabela[2][0] == 'X')))
    {
        return 1;
    }

    return 0;
}

int checaFim(char **tabela)
{
    if (checaLinha(tabela) == 1)
    {
        return 1;
    }
    else if (checaLinha(tabela) == 2)
    {
        return 2;
    }

    if (checaColuna(tabela) == 1)
    {
        return 1;
    }
    else if (checaColuna(tabela) == 2)
    {
        return 2;
    }

    if (checaDiagonalPrincipal(tabela) == 1)
    {
        return 1;
    }
    else if (checaDiagonalPrincipal(tabela) == 2)
    {
        return 2;
    }

    if (checaDiagonalSecundaria(tabela) == 1)
    {
        return 1;
    }
    else if (checaDiagonalSecundaria(tabela) == 2)
    {
        return 2;
    }

    return 0;
}

int nroJogadas(char **tabela)
{
    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (tabela[i][j])
            {
            case 'X':
            case 'O':
                cont++;
                break;
            default:
                break;
            }
        }
    }

    return cont;
}



/*Jogador ranking(int *tamanho)
{

    Jogador *lista;

    FILE *arquivo;
    arquivo = fopen("ranking.txt", "r");

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", tamanho);

        lista = malloc(tamanho * sizeof(Jogador));

        for (int i = 0; i < *tamanho; i++)
        {
            Jogador jogador;
            fgetc(arquivo);
            fgets(jogador.nome, 20, arquivo);

            int tamNome = strlen(jogador.nome);
            jogador.nome[tamNome - 1] = '\0';

            fscanf(arquivo, "%d", &jogador.vitoria);
            fscanf(arquivo, "%d", &jogador.empate);
            fscanf(arquivo, "%d", &jogador.derrota);

            lista[i] = jogador;
        }


        fclose(arquivo);
        return 
    }

void mostrarRanking(){
        FILE *arquivo2;
        arquivo2 = fopen("ranking.txt", "r");
        printf("\n ######- Ranking de Jogadores -######\n");
        printf("  \n");
        printf(" NOME - VITÓRIAS - EMPATES - DERROTAS\n");

        Jogador jogador;
        
        for (int i = 0; i < 10; i++)
        {
            fscanf(arquivo2, "%s %d %d %d ",  &lista->vitoria, &lista->empate, &lista->derrota);
            printf("%d %s %d %d %d", i, lista->nome, lista->vitoria, lista->empate, lista->derrota);
        }
        
        printf("\n\n");
        fclose(arquivo2);
}*/

int salvaJogo(char entrada[], char **tabela)
    {
        FILE *arquivo = fopen(entrada, "w");

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                imprimeTabela(tabela);
                fprintf(arquivo, " %c ", tabela[i][j]);
            }
        }
        printf("\n");
        printf("    Jogo salvo!");

        fclose(arquivo);
        return 0;
    }
#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

// recebe o local (linha e coluna) passado na função realizarJogada1 e marca no local desejado
void marcarJogada1(char ***tabela, int linha, int coluna, int vez)
{
    if (vez % 2 != 0) //vez do jogador 1, marca como X
    {
        (*tabela)[linha][coluna] = 'X';
    }
    else //vez do computador, marca como O
    {
        (*tabela)[linha][coluna] = 'O';
    }
}

// pede um comando para o usuário e verifica o que ele quer
// também faz a jogada do pc, impedindo o usuário de ganhar como prioridade e vencendo se tiver chance

//recebe como parâmetro uma flag, que vai dizer se o jogador está começando um jogo novo ou se digitou "voltar" no menu incial
int realizarJogada1(char ***tabela, int flag, Jogador *jogador) //e recebe o nome do jogador que foi pedido no menu de funcoes.c
{

    system("clear"); //limpa a tela
    char comando[10], comando2[20]; //recebe os comandos do usuário
    int jogadas; //quantifica as jogadas feitas
    int vez = 1; //faz a diferenciação da vez, se for impar é o jogador e par é o computador; vai aumentando a cada jogada
    Jogador jog2; //inicializa a variavel jog2
    char **tabela2 = criaTabela(); //inicializa tabela
    strcpy(jog2.nome, "Computador"); ////copia o nome "Computador para jog2.nome"

    if (flag == 1) //flag 1 é um novo jogo
    {

        jogadas = 0; //jogadas se iniciam em 0
    }
    if (flag != 1) //flag diferente de 1 é um jogo em andamento
    {
        for (int i = 0; i < 3; i++) //copia a tabela anterior para uma nova tabela
        {
            for (int j = 0; j < 3; j++)
            {
                tabela2[i][j] = (*tabela)[i][j];
            }
        }
        jogadas = nroJogadas(tabela2); //jogadas recebe o número de jogadas contabilizadas na função nroJogadas
    }

    imprimeTabela(tabela2); //imprime a tabela

    do //fica em loop até alguém vencer ou der 9 jogadas
    {
        if (vez % 2 != 0) //vez do jogador 1
        {
            //recebe o primeiro comando que o usuário digitar
            printf("\n");
            printf("    %s, digite o comando: ", jogador->nome);
            scanf("%s", comando);

            if (strcmp(comando, "marcar") == 0)
            {
                //se for marcar, recebe o comando 2 que é o local a ser marcado
                scanf("%s", comando2);
                int local = atoi(comando2); //tranforma o char em int
                int coluna = (local % 10) - 1; 
                int linha = (local / 10) - 1;

                while (checaLocal(tabela2, linha, coluna) == 0) //checa se o local está disponível; retorna 1 se sim e 0 se não
                {
                    printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jogador->nome); //pede outra comando enquanto checaLOcal retornar 0
                    scanf("%s%s", comando, comando2);
                    int local = atoi(comando2);
                    coluna = (local % 10) - 1;
                    linha = (local / 10) - 1;
                }
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
                jogadas++;
            }
            else if (strcmp(comando, "voltar") == 0) //volta para o menu
            {
                system("clear");
                return 0;
            }
            else if (strcmp(comando, "salvar") == 0)
            {
                //pede o nome do arquivo
                scanf("%s", comando2);
                vez--; //diminiu a vez para que o jogador não perca a vez de marcar na tabela
                salvaJogo1(comando2, tabela2, *jogador, 1, 2); //salva jogo playerVSpc, recebe como parâmetro
                //nome do arquivo a ser salvo, tabela, nome do jogador 1, quantos jogadores tem e de quem foi o último
                //movimento, neste caso vai ser sempre o computador
            }
            else //se o comando digitado não for voltar, salvar e voltar fica num loop pedindo e verificando tudo de novo
            {
                do
                {
                    printf(BOLD(RED("    Comando não encontrado!")));
                    printf("\n\n");
                    getchar();
                    printf("   %s, digite o comando: ", jogador->nome);
                    scanf("%s", comando);
                } while ((strcmp(comando, "marcar") != 0) && (strcmp(comando, "voltar") != 0) && (strcmp(comando, "salvar") != 0));
                if (strcmp(comando, "marcar") == 0)
                {
                    scanf("%s", comando2);
                    int local = atoi(comando2);
                    int coluna = (local % 10) - 1;
                    int linha = (local / 10) - 1;

                    while (checaLocal(tabela2, linha, coluna) == 0)
                    {
                        printf(BOLD(RED("   Posição ocupada ou inexistente, tente de novo!")));
                        printf("\n\n");
                        printf("    %s, digite o comando: ", jogador->nome);
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
                    system("clear");
                    return 0;
                }
                else if (strcmp(comando, "salvar") == 0)
                {
                    scanf("%s", comando2);
                    vez--;
                    salvaJogo1(comando2, tabela2, *jogador, 1, 2);
                }
            }
        }
        else //vez impar, computador faz a jogada
        {
            printf("\n");
            printf("    Vez do computador!");
            printf("\n");

            if (vez == 2) //primeija jogada. Não tem lógica, só marca em uma posição aleatória
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
                //comeca a verificação para impedir o jogador de ganhar
            else if (((tabela2[0][0] == 'X' && tabela2[2][2] == 'X') || (tabela2[0][2] == 'X' && tabela2[2][0] == 'X')) && checaLocal(tabela2, 2, 1) == 1)
            {
                int linha = 2;
                int coluna = 1;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][0] == 'X' && tabela2[0][1] == 'X') || (tabela2[0][0] == 'O' && tabela2[0][1] == 'O')) && checaLocal(tabela2, 0, 2) == 1)
            {
                int linha = 0;
                int coluna = 2;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][0] == 'X' && tabela2[0][2] == 'X') || (tabela2[0][0] == 'O' && tabela2[0][2] == 'O')) && checaLocal(tabela2, 0, 1) == 1)
            {
                int linha = 0;
                int coluna = 1;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][1] == 'X' && tabela2[0][2] == 'X') || (tabela2[0][1] == 'O' && tabela2[0][2] == 'O')) && checaLocal(tabela2, 0, 0) == 1)
            {
                int linha = 0;
                int coluna = 0;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[1][0] == 'X' && tabela2[1][1] == 'X') || (tabela2[1][0] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 1, 2) == 1)
            {
                int linha = 1;
                int coluna = 2;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[1][0] == 'X' && tabela2[1][2] == 'X') || (tabela2[1][0] == 'O' && tabela2[1][2] == 'O')) && checaLocal(tabela2, 1, 1) == 1)
            {
                int linha = 1;
                int coluna = 1;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[1][1] == 'X' && tabela2[1][2] == 'X') || (tabela2[1][1] == 'O' && tabela2[1][2] == 'O')) && checaLocal(tabela2, 1, 0) == 1)
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
            else if (((tabela2[2][1] == 'X' && tabela2[2][2] == 'X') || (tabela2[2][1] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 2, 0) == 1)
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
            else if (((tabela2[1][0] == 'X' && tabela2[2][0] == 'X') || (tabela2[1][0] == 'O' && tabela2[2][0] == 'O')) && checaLocal(tabela2, 0, 0) == 1)
            {
                int linha = 0;
                int coluna = 0;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][0] == 'X' && tabela2[2][0] == 'X') || (tabela2[0][0] == 'O' && tabela2[2][0] == 'O')) && checaLocal(tabela2, 1, 0) == 1)
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
            else if (((tabela2[1][1] == 'X' && tabela2[2][1] == 'X') || (tabela2[1][1] == 'O' && tabela2[2][1] == 'O')) && checaLocal(tabela2, 0, 1) == 1)
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
            else if (((tabela2[1][2] == 'X' && tabela2[2][2] == 'X') || (tabela2[1][2] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 0, 2) == 1)
            {
                int linha = 0;
                int coluna = 2;
                marcarJogada1(&tabela2, linha, coluna, vez);
                imprimeTabela(tabela2);
            }
            else if (((tabela2[0][2] == 'X' && tabela2[2][2] == 'X') || (tabela2[0][2] == 'O' && tabela2[2][2] == 'O')) && checaLocal(tabela2, 1, 2) == 1)
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
            else if (((tabela2[2][2] == 'X' && tabela2[1][1] == 'X') || (tabela2[2][2] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 0, 0) == 1)
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
            else if (((tabela2[2][0] == 'X' && tabela2[1][1] == 'X') || (tabela2[2][0] == 'O' && tabela2[1][1] == 'O')) && checaLocal(tabela2, 0, 2) == 1)
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

    if (checaFim(tabela2) == 1) //checa fim retorna 1 se o jogador ganhou
    {
        printf("\n   Parabéns" BOLD(GREEN(" %s")) ", você ganhou!", jogador->nome);

        jogador->empates = 0;
        jogador->derrotas = 0;
        jogador->vitorias++;
        inserirNoRanking(*jogador);

        jog2.vitorias = 0;
        jog2.empates = 0;
        jog2.derrotas++;
        inserirNoRanking(jog2);
        printf("\n");
    }
    else if (checaFim(tabela2) == 2) //checa fim retorna 2 se o computador ganhou
    {

        printf("\n   " BOLD(GREEN("%s")) " ganhou!", jog2.nome);

        jog2.empates = 0;
        jog2.derrotas = 0;
        jog2.vitorias++;
        inserirNoRanking(jog2);

        jogador->vitorias = 0;
        jogador->empates = 0;
        jogador->derrotas++;
        inserirNoRanking(*jogador);
        printf("\n");
    }
    else //checa fim retorna 0 se deu empate
    {
        printf("\n    Deu velha!\n\n");
        jogador->vitorias = 0;
        jogador->derrotas = 0;
        jogador->empates++;
        inserirNoRanking(*jogador);

        jog2.vitorias = 0;
        jog2.derrotas = 0;
        jog2.empates++;
        inserirNoRanking(jog2);
        printf("\n");
    }
    getchar();
    printf(BOLD(YELLOW("\n   Digite qualquer tecla para continuar! ")));
    scanf("%c", &carac);

    liberaTabela(tabela2); //função libera tabela, libera uma matriz alocada dinamicamente. Presente em funcoes.c
    system("clear");
    return 0;
}

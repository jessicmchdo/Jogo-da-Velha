#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

// recebe o local (linha e coluna) passado na função realizarJogada e marca no local desejado
void marcarJogada2(char ***tabela, int linha, int coluna, int vez)
{
    if (vez % 2 != 0) //vez do jogador 1, marca como X
    {
        (*tabela)[linha][coluna] = 'X';
    }
    else
    {
        (*tabela)[linha][coluna] = 'O'; //vez do jogador 2, marca como O
    }
}

// pede um comando para os usuários e verifica o que eles quer em
int realizarJogada2(char ***tabela, int flag, Jogador *jog1, Jogador *jog2)
{ // faz jogadas com 2 jogadores
    system("clear");
    char comando[10], comando2[20]; //pega os dois comandos
    int jogadas; //contador de jogadas
    int vez = 1; //contador de vez, impar se for a vez do jogador 1 e par do jogador 2

    char **tabela2 = criaTabela(); //cria uma tabela dinamicamente
    if (flag == 1) //se a flag for 1 inicia um jogo novo
    {
        jogadas = 0; //jogadas se iniciam em 0
    }
    else //outro valor para a flag é uma jogada já em andamento que o usuário deseja continuar jogando
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                tabela2[i][j] = (*tabela)[i][j]; //copia a tabela anterior para uma nova tabela
            }
        }
        jogadas = nroJogadas(tabela2); //jogada recebe o numero de jogadas anteriores feitas, contabilizadas na função nroJogadas
    }
    system("clear"); //limpa a tela
    imprimeTabela(tabela2); //imprime a tabela sem nada, para que o usuário veja como está disposta

    do
    {
        if (vez % 2 != 0) //impar, vez do jogador 1 fazer a jogada
        {
            printf("\n");
            printf("    %s, digite o comando: ", jog1->nome); //pede o comando salvar, voltar ou marcar
            scanf("%s", comando);

            if (strcmp(comando, "marcar") == 0) //comando marcar recebe o local em char, converte para int e depois separa em 
                                                //linha e coluna
            {
                scanf("%s", comando2);
                int local = atoi(comando2);
                int coluna = (local % 10) - 1;
                int linha = (local / 10) - 1;

                while (checaLocal(tabela2, linha, coluna) == 0) //verifica se a o local está disponível, fica em loop se não estiver
                {
                    printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog1->nome); //pede de novo o comando
                    scanf("%s%s", comando, comando2);
                    int local = atoi(comando2);
                    coluna = (local % 10) - 1;
                    linha = (local / 10) - 1;
                }
                marcarJogada2(&tabela2, linha, coluna, vez); //quando estiver disponível, marca a jogada na função e atualiza a tabela
                imprimeTabela(tabela2);
                jogadas++;
            }
            else if (strcmp(comando, "voltar") == 0) //volta para o menu
            {
                system("clear"); //limpa a tela
                return 0;
            }
            else if (strcmp(comando, "salvar") == 0) //se for salvar pede um comando novo que será o nome do arquivo
            {
                scanf("%s", comando2);
                vez--; //diminui o contador de vez para que o jogador não perca a vez
                salvaJogo2(comando2, tabela2, *jog1, *jog2, 2, 2); //salva o jogo de dois jogadores
                //recebe como parametro o nome do arquivo, a tabela, o nome dos dois jogadores, quant de jogadores
                //e quem fez a última jogada
            }
            else //caso o usuário não tenha digitado voltar, salvar nem marcar
            {
                do //fica em loop refazendo a pergunta do comando, verifica se a posição está ocupada ou não, marca
                //volta e salva
                {
                    printf(BOLD(RED("    Comando não encontrado!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog1->nome);
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
                        printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!")));
                        printf("\n\n");
                        printf("    %s, digite o comando: ", jog1->nome);
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
                    system("clear");
                    return 0;
                }
                else if (strcmp(comando, "salvar") == 0)
                {
                    scanf("%s", comando2);
                    vez--;
                    salvaJogo2(comando2, tabela2, *jog1, *jog2, 2, 2);
                }
            }
        }
        else //else para vez do jogador 2
        {
            printf("\n");
            printf("    %s, digite o comando: ", jog2->nome); //pede o primeiro comando salvar, marcar ou voltar
            scanf("%s", comando);

            if (strcmp(comando, "marcar") == 0) //se for marcar pede o segundo
            {
                scanf("%s", comando2);
                int local = atoi(comando2); //tranforma char em int e depois separa em linha e coluna
                int coluna = (local % 10) - 1; //o -1 serve para marcar na posição real da tabela que inicia em 0 e vai até 2
                                                // o usuário vai digitar de 1 até 3
                int linha = (local / 10) - 1;

                while (checaLocal(tabela2, linha, coluna) == 0) //verifica se a linha e coluna digitada está livre
                {                                               // 0 se não estiver e 1 se estiver
                    printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!"))); //se não pede de novo
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog2->nome);
                    scanf("%s%s", comando, comando2);
                    int local = atoi(comando2);
                    coluna = (local % 10) - 1;
                    linha = (local / 10) - 1;
                }
                marcarJogada2(&tabela2, linha, coluna, vez); //marca a jogada na função que está logo acima
                imprimeTabela(tabela2); //imprime a tabela
                jogadas++; //incrementa uma jogada
            }
            else if (strcmp(comando, "voltar") == 0) // verifica se o usuário digitou voltar
            {
                system("clear"); //limpa a tela e volta para o menu
                printf("\n");
                return 0;
            }
            else if (strcmp(comando, "salvar") == 0) //verifica se o usuário digitou salvar
            {
                scanf("%s", comando2); //pega o comando2 que será o nome do arquivo
                vez--; //diminui a vez para que o jogador não perca a vez
                salvaJogo2(comando2, tabela2, *jog1, *jog2, 2, 1); //salva o jogo de dois jogadores
                //recebe como parametro o nome do arquivo, a tabela, o nome dos dois jogadores, quant de jogadores
                //e quem fez a última jogada
            }
            else //caso o usuário não tenha digitado nenhum dos 3 comandos anteriores, fica em loop até que um seja digitado
            //pede e verifica todos os comandos que antes foram explicados
            {
                do
                {
                    printf(BOLD(RED("    Comando não encontrado!")));
                    printf("\n\n");
                    printf("    %s, digite o comando: ", jog2->nome);
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
                        printf(BOLD(RED("    Posição ocupada ou inexistente, tente de novo!")));
                        printf("\n\n");
                        printf("    %s, digite o comando: ", jog2->nome);
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
                    system("clear");
                    return 0;
                }
                else if (strcmp(comando, "salvar") == 0)
                {
                    scanf("%s", comando2);
                    vez--;
                    salvaJogo2(comando2, tabela2, *jog1, *jog2, 2, 1);
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                (*tabela)[i][j] = tabela2[i][j];
            }
        }

        vez++; //aumenta a vez para que seja a vez do jogador 1

    } while (checaFim(tabela2) == 0 && jogadas < 9);

    char carac;

    if (checaFim(tabela2) == 1)
    {
        printf("\n    Parabéns " BOLD(GREEN("%s")) ", você ganhou!", jog1->nome);

        printf("\n");
    }
    else if (checaFim(tabela2) == 2)
    {
        printf("\n    Parabéns " BOLD(GREEN(" %s")) ", você ganhou!", jog2->nome);

        printf("\n");
    }
    else
    {
        printf("\n    Deu velha!\n\n");
        
        printf("\n");
    }
    getchar();
    printf(BOLD(YELLOW("\n    Digite qualquer tecla para continuar! ")));
    scanf("%c", &carac);

    liberaTabela(tabela2); //libera a tabela alocada dinamicamente
    system("clear");
    return 0;
}

#ifndef _FUNCOES_H_INCLUDED
#define _FUNCOES_H_INCLUDED

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

#include <stdio.h>

// cores e formato de texto
#define ANSI_RESET "\x1b[0m" // desativa os efeitos anteriores
#define ANSI_BOLD "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_BG_COLOR_BLACK "\x1b[40m"
#define ANSI_BG_COLOR_RED "\x1b[41m"
#define ANSI_BG_COLOR_GREEN "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW "\x1b[43m"
#define ANSI_BG_COLOR_BLUE "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN "\x1b[46m"
#define ANSI_BG_COLOR_WHITE "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string) ANSI_BOLD string ANSI_RESET
#define BLACK(string) ANSI_COLOR_BLACK string ANSI_RESET
#define BLUE(string) ANSI_COLOR_BLUE string ANSI_RESET
#define RED(string) ANSI_COLOR_RED string ANSI_RESET
#define GREEN(string) ANSI_COLOR_GREEN string ANSI_RESET
#define YELLOW(string) ANSI_COLOR_YELLOW string ANSI_RESET
#define BLUE(string) ANSI_COLOR_BLUE string ANSI_RESET
#define MAGENTA(string) ANSI_COLOR_MAGENTA string ANSI_RESET
#define CYAN(string) ANSI_COLOR_CYAN string ANSI_RESET
#define WHITE(string) ANSI_COLOR_WHITE string ANSI_RESET
#define BG_BLACK(string) ANSI_BG_COLOR_BLACK string ANSI_RESET
#define BG_BLUE(string) ANSI_BG_COLOR_BLUE string ANSI_RESET
#define BG_RED(string) ANSI_BG_COLOR_RED string ANSI_RESET
#define BG_GREEN(string) ANSI_BG_COLOR_GREEN string ANSI_RESET
#define BG_YELLOW(string) ANSI_BG_COLOR_YELLOW string ANSI_RESET
#define BG_BLUE(string) ANSI_BG_COLOR_BLUE string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string) ANSI_BG_COLOR_CYAN string ANSI_RESET
#define BG_WHITE(string) ANSI_BG_COLOR_WHITE string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL "\u250F"  // ┏ (top-left)
#define TAB_ML "\u2523"  // ┣ (middle-left)
#define TAB_BL "\u2517"  // ┗ (bottom-left)
#define TAB_TJ "\u2533"  // ┳ (top-join)
#define TAB_MJ "\u254B"  // ╋ (middle-join)
#define TAB_BJ "\u253B"  // ┻ (bottom-join)
#define TAB_TR "\u2513"  // ┓ (top-right)
#define TAB_MR "\u252B"  // ┫ (middle-right)
#define TAB_BR "\u251B"  // ┛ (bottom-right)

void menu(); // imprime o menu
char **criaTabela(); //cria uma tabela
void liberaTabela(char **tabela); //libera tabela
void imprimeTabela(char **tabela); // imprime tabela
void liberaTabela2(char ***tabela); // libera tabela
int checaLocal(char **tabela, int linha, int coluna); //checa se o local que o usuário digitou está vazio
int checaLinha(char **tabela); //verifica se uma linha está preenchida
int checaColuna(char **tabela); //verifica se uma coluna está preenchida
int checaDiagonalPrincipal(char **tabela); //verifica se a diagonal principal está preenchida
int checaDiagonalSecundaria(char **tabela); //verifica se a diagonal secundária está preenchida
int checaFim(char **tabela); //verifica se o jogo acabou
int nroJogadas(char **tabela); //guarda o numero de jogadas feitas
void marcarJogada2(char ***tabela, int linha, int coluna, int vez); //marca jogadas de playerVSplayer
int realizarJogada2(char ***tabela, int flag, Jogador *jog1, Jogador *jog2); // faz jogadas com 2 pessoas
void marcarJogada1(char ***tabela, int linha, int coluna, int vez); //marca jogadas de playerVSpc
int realizarJogada1(char ***tabela, int flag, Jogador *jogador); //faz jogadas de 1 jogador
int file_exists(const char *filename); //checa se um arquivo existe ou não
int salvaJogo1(char entrada[], char **tabela, Jogador jog1, int quantJog, int ultimaJog); //salva o jogo playerVSpc
int salvaJogo2(char entrada[], char **tabela, Jogador jog1, Jogador jog2, int quantJog, int ultimaJog); //salva jogo playerVSplayer
void continuarJogo (char nomeArquivo[]); //abrir arquivo salvoo
Jogador *ranking(int *tamanho); //criar ranking
void inserirNoRanking(Jogador jogador); //inserir no ranking
void mostrarRanking(); //mostrar no ranking

#endif
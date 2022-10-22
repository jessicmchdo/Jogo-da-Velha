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


void menu(); // ok
char **criaTabela();
void liberaTabela(char **tabela);
void imprimeTabela(char **tabela); // ok
void limpaTabela(char ***tabela);
void liberaTabela2(char ***tabela);
int checaLocal(char **tabela, int linha, int coluna);
int checaLinha(char **tabela);
int checaColuna(char **tabela);
int checaDiagonalPrincipal(char **tabela);
int checaDiagonalSecundaria(char **tabela);
int checaFim(char **tabela);
int nroJogadas(char **tabela);
void marcarJogada2(char ***tabela, int linha, int coluna, int vez);
int realizarJogada2(char ***tabela, int flag); // faz jogadas com 2 pessoas
// void compJoga(char **tabela, int linha, int coluna, int vez);
void marcarJogada1(char ***tabela, int linha, int coluna, int vez);
int realizarJogada1(char ***tabela, int flag);
Jogador ranking(int *tamanho);
void mostrarRanking();
int salvaJogo(char entrada[], char **tabela);

#endif
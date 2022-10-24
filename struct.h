#ifndef _STRUCT_H_INCLUDED
#define _STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    char nome[50];
    int vitorias;
    int derrotas;
    int empates;
} Jogador;

typedef struct
{
    int quantJogadores;
    char nomeJog1[50];
    char nomeJog2[50];
    char tabela[3][3];
    int ultimaJogada;
} Jogo; //vai ser útil para salvar em um arquivo

typedef struct
{
    bool novoJogo; //verifica s
    bool continua;
    int jogada;
} Info;

#endif
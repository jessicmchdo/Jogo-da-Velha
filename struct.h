#ifndef _STRUCT_H_INCLUDED
#define _STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    char nome[20];
    int vitoria;
    int derrota;
    int empate;
} Jogador;

typedef struct
{
    bool novoJogo;
    bool continua;
    int jogada;
} Info;

#endif
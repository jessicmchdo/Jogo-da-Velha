#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

int main()
{
    printf("\n\n");
    printf(BOLD(CYAN("      ██  ██████   ██████   ██████      ██████   █████      ██    ██ ███████ ██      ██   ██  █████  ")));
    printf(BOLD(CYAN("\t\t\t\n      ██ ██    ██ ██       ██    ██     ██   ██ ██   ██     ██    ██ ██      ██      ██   ██ ██   ██ ")));
    printf(BOLD(CYAN("\t\t\t\n      ██ ██    ██ ██   ███ ██    ██     ██   ██ ███████     ██    ██ █████   ██      ███████ ███████ ")));
    printf(BOLD(CYAN("\t\t\t\n ██   ██ ██    ██ ██    ██ ██    ██     ██   ██ ██   ██      ██  ██  ██      ██      ██   ██ ██   ██ ")));
    printf(BOLD(CYAN("\t\t\t\n  █████   ██████   ██████   ██████      ██████  ██   ██       ████   ███████ ███████ ██   ██ ██   ██ ")));

    menu();
    return 0;
}

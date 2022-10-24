#include "funcoes.h"
#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define n 3

// imprime menu
void menu()
{
    int op1, op2;
    char **tabela = criaTabela();
    Info info;
    Jogador jog1, jog2;
    char jogo[30];

    do
    {

        printf("\n\n");
        printf(BOLD("  0. Sair do Jogo\n"));
        printf(BOLD("  1. Começar um novo jogo\n"));
        printf(BOLD("  2. Continuar um jogo salvo\n"));
        printf(BOLD("  3. Continuar o jogo atual\n"));
        printf(BOLD("  4. Exibir o ranking\n")); // tem que atualizar e deixar bonito
        printf(BOLD("  Durante o jogo digite \"voltar\" para retornar ao menu\n\n"));
        printf(BOLD("  Escolha a opção: "));

        scanf("%d", &op1);
        switch (op1)
        {
        case 1: // novo jogo
            printf(BOLD("  Digite o número de jogadores (1 ou 2): "));
            scanf("%d", &op2);

            switch (op2)
            {
            case 1: // player vs pc
                getchar();
                printf(BOLD("    Digite do nome do jogador 1: "));
                fgets(jog1.nome, 50, stdin);
                int tam1 = strlen(jog1.nome);
                jog1.nome[tam1 - 1] = '\0';

                if (strcmp(jog1.nome, "Computador") == 0 || strcmp(jog1.nome, "computador") == 0)
                {
                    do
                    {
                        printf(BOLD(RED("\n    Nome inválido!")));
                        printf(BOLD("\n   Digite o nome do jogador 1: "));
                        fgets(jog1.nome, 50, stdin);
                    } while (strcmp(jog1.nome, "Computador") == 0 || strcmp(jog1.nome, "computador") == 0);
                }
                realizarJogada1(&tabela, 1, &jog1);
                info.continua = true;
                info.jogada = 1;
                break;
            case 2: // player vs player
                getchar();
                printf(BOLD("   Digite do nome do jogador 1: "));
                fgets(jog1.nome, 50, stdin);

                if (strcmp(jog1.nome, "Computador") == 0 || strcmp(jog1.nome, "computador") == 0)
                {
                    do
                    {
                        printf(BOLD(RED("\n    Nome inválido!")));
                        printf(BOLD("\n    Digite o nome do jogador 1: "));
                        fgets(jog1.nome, 50, stdin);
                    } while (strcmp(jog1.nome, "Computador") == 0 || strcmp(jog1.nome, "computador") == 0);
                }

                printf(BOLD("   Digite do nome do jogador 2: "));
                fgets(jog2.nome, 50, stdin);

                if (strcmp(jog1.nome, jog2.nome) == 0 || strcmp(jog2.nome, "Computador") == 0 || strcmp(jog2.nome, "Computador") == 0)
                {
                    do
                    {
                        printf(BOLD(RED("\n    Nome inválido!")));
                        printf(BOLD("\n   Digite o nome do jogador 2: "));
                        fgets(jog2.nome, 50, stdin);
                    } while (strcmp(jog1.nome, jog2.nome) == 0 || strcmp(jog2.nome, "Computador") == 0 || strcmp(jog2.nome, "Computador") == 0);
                }
                int tam2 = strlen(jog1.nome);
                int tam3 = strlen(jog2.nome);
                jog1.nome[tam2 - 1] = '\0';
                jog2.nome[tam3 - 1] = '\0';

                realizarJogada2(&tabela, 1, &jog1, &jog2);
                info.continua = true;
                info.jogada = 2;
                break;
            default:
                printf(BOLD(RED("    Opção inválida\n\n")));
                break;
            }
            break;

        case 0:
            return;
        case 2:
            printf(BOLD("  Digite o nome do arquivo a ser aberto: "));
            getchar();
            fgets(jogo, 30, stdin);
            int tamanho = strlen(jogo);
            jogo[tamanho - 1] = '\0';
            continuarJogo(jogo);
            break;
        case 4: // mostra ranking
            mostrarRanking();
            printf(BOLD(CYAN("  Pressione qualquer tecla para voltar! ")));
            break;
        case 3: // continua jogo atual
            if (info.continua == true)
            {
                if (info.jogada == 2)
                {
                    realizarJogada2(&tabela, 5, &jog1, &jog2);
                    system("clear");
                }
                else
                {
                    realizarJogada1(&tabela, 5, &jog1);
                    system("clear");
                }
            }
            else
            {
                printf(BOLD(RED("  Não existe nenhum jogo em andamento!")));
            }
            break;
        default:
            printf(BOLD(RED("    Opção inválida")));
            break;
        }
    } while ((op1 != 0) || (op1 > 4));
    return;
}

// cria tabela alocando dinamicamente e inicializa com espaços em branco
char **criaTabela()
{
    char **tabela;
    // alocar dinamicamente o tabela, note que no comeco do arquivo defini n como 3
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

// libera tabela
void liberaTabela(char **tabela)
{
    for (int i = 0; i < n; i++)
    {
        free(tabela[i]);
    }
    free(tabela);
}
// libera tabela
void liberaTabela2(char ***tabela)
{
    for (int i = 0; i < n; i++)
    {
        free(*tabela[i]);
    }
    free(*tabela);
}

void imprimeTabela(char **tabela)
{
    // imprimiu a tabela do jeito que eu queria
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

// checa se o local (linha e coluna) digitado pelo usuário (nas funções realizarJogada1(playerVSpc) e realizarJogada(playerVSplayer))
// está vazio
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
// verfica se uma linha completa está preenchida
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
// verfica se uma coluna completa está preenchida
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
// verfica se a diagonal principal completa está preenchida
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
// verfica se a diagonal secundária completa está preenchida
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

// recebe os resultados das funcoes checaLinha, checaColuna, checaDiagonalPrincipal e checaDiagonalSecundária e verifica se
// o jogador ganhou em alguma dessas
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

// faz a contagem do numero de jogadas em determinada tabela
int nroJogadas(char **tabela)
{
    int cont = 0; //contador de jogadas feitas, vai ser aumentado se houver X ou O na tabela
    for (int i = 0; i < 3; i++) //for para linha variando de 0 a 3
    {
        for (int j = 0; j < 3; j++) //for para coluna variando de 0 a 3
        {
            switch (tabela[i][j]) //se na tabela na posição linha i coluna j houver X ou O
            {
            case 'X':
            case 'O':
                cont++; //o contador aumenta 1
                break;
            default: //se não, fecha o loop da tabela na posição linha i coluna j
                break;
            }
        }
    }

    return cont; //retorna esse contador, que em outras funções vai ser o número de jogadas
}

// verifica se o arquivo existe
int file_exists(const char *filename)
{
    FILE *file;
    if ((file = fopen(filename, "r")))
    {

        fclose(file);
        return 1;
    }
    return 0;
}
// salva jogo playerVSpc
int salvaJogo1(char entrada[], char **tabela, Jogador jog1, int quantJog, int ultimaJog)
{
    if (!file_exists(entrada)) //verifica se o arquivo existe. No modo escrita, é necessário que o arquivo não exista se não
                                //perdemos a informação guardada em um arquivo de mesmo nome
    {
        FILE *arquivo1 = fopen(entrada, "w"); //abre o arquivo no modo escrita
        char c;

        fprintf(arquivo1, "%d\n", quantJog); //grava quant de jogadores
        fprintf(arquivo1, "%s\n", jog1.nome); //grava nome do jogador 1
        for (int linha = 0; linha < 3; linha++)
        {
            for (int coluna = 0; coluna < 3; coluna++)
            {
                if (tabela[linha][coluna] == ' ') //se na posição existir um espaço em branco, insere um -
                {
                    c = '-';
                    fprintf(arquivo1, "%c ", c);
                }
                else //se não tiver espaço em branco, grava o que tiver lá
                {
                    fprintf(arquivo1, "%c ", tabela[linha][coluna]);
                }
            }
            fprintf(arquivo1, "\n");
        }
        fprintf(arquivo1, "%d\n", ultimaJog); //salva quem fez a ultima jogada
        printf(BOLD(GREEN("\n  Arquivo \"%s\" salvo com sucesso!\n\n")), entrada); //mensagem de sucesso

        fclose(arquivo1); //fecha o arquivo
        return 1;
    }
    else //se existir um arquivo com o mesmo nome
    {
        printf(BOLD(RED("  Não foi possível salvar este arquivo!"))); //mensagem de erro
        return 0;
    }
}
// salva jogo playerVSplayer
int salvaJogo2(char entrada[], char **tabela, Jogador jog1, Jogador jog2, int quantJog, int ultimaJog)
{
    if (!file_exists(entrada)) //verifica se o arquivo não existe, condição necessária 
                                //para o modo "w" não sobreescrever um arquivo existente
    {
        FILE *arquivo1 = fopen(entrada, "w"); 
        char c;

        fprintf(arquivo1, "%d\n", quantJog); //escreve no arquivo a quant de jogadores
        fprintf(arquivo1, "%s\n", jog1.nome); // escreve no arquivo o noe do jogador 1
        fprintf(arquivo1, "%s\n", jog2.nome); //escreve no arquivo o nome do jogador 2
        for (int linha = 0; linha < 3; linha++)
        {
            for (int coluna = 0; coluna < 3; coluna++)
            {
                if (tabela[linha][coluna] == ' ') //se na tabela na posição linha i e coluna j tiver um espaço em branco
                {
                    c = '-';
                    fprintf(arquivo1, " %c ", c); //escreve no arquivo o caractere -
                }
                else
                {
                    fprintf(arquivo1, " %c ", tabela[linha][coluna]); //se não tiver espaço em branco escreve o que está lá
                                                                    // no caso X e O
                }
            }
            fprintf(arquivo1, "\n");
        }
        fprintf(arquivo1, "%d\n", ultimaJog); //escreve quem fez a última jogada
        printf(BOLD(GREEN("\n  Arquivo \"%s\" salvo com sucesso!\n\n")), entrada); //mensagem de sucesso

        fclose(arquivo1); //fecha o arquivo
        return 1; 
    }
    else //caso o arquivo já exista
    {
        printf(BOLD(RED("  Não foi possível salvar este arquivo!"))); //mensagem de erro
        return 0;
    }
}

// cria ranking
Jogador *ranking(int *tamanho)
{

    Jogador *lista;

    FILE *arquivo;
    arquivo = fopen("ranking.txt", "r");

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", tamanho);

        lista = malloc(*tamanho * sizeof(Jogador));

        for (int i = 0; i < *tamanho; i++)
        {
            Jogador jogador;
            fgets(jogador.nome, 20, arquivo);

            int tamNome = strlen(jogador.nome);
            jogador.nome[tamNome - 1] = '\0';

            fscanf(arquivo, "%d", &jogador.vitorias);
            fscanf(arquivo, "%d", &jogador.empates);
            fscanf(arquivo, "%d", &jogador.derrotas);
            // fgetc(arquivo);

            lista[i] = jogador;
        }
    }
    fclose(arquivo);
    return lista;
}

// insere um jogador no ranking
void inserirNoRanking(Jogador jogador)
{
    FILE *arquivo = fopen("ranking.txt", "w+");

    fprintf(arquivo, "%s\n", jogador.nome);
    fprintf(arquivo, "%d", jogador.vitorias);
    fprintf(arquivo, "%d", jogador.empates);
    fprintf(arquivo, "%d", jogador.derrotas);

    fclose(arquivo);
}

// imprime o ranking
void mostrarRanking()
{

    Jogador jogador;
    int tamanho;
    char carac;
    FILE *arquivo2;
    arquivo2 = fopen("ranking.txt", "r");
    printf("\n ....:::: Ranking de Jogadores ::::....\n");
    printf("  \n");
    printf("    " TAB_VER "\tNOME\t\t" TAB_VER "  VITÓRIAS  " TAB_VER "  EMPATES  " TAB_VER "  DERROTAS \n");
    printf(TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR TAB_HOR "\n");

    fscanf(arquivo2, "%d", &tamanho);
    fgetc(arquivo2);
    for (int i = 0; i < tamanho; i++)
    {
        fgets(jogador.nome, 20, arquivo2);
        int tamNome = strlen(jogador.nome);
        jogador.nome[tamNome - 1] = '\0';

        fscanf(arquivo2, "%d %d %d ", &jogador.vitorias, &jogador.empates, &jogador.derrotas);
        printf(" %d. " TAB_VER " %s\t\t" TAB_VER "  %d\t" TAB_VER "%d\t" TAB_VER "%d ", i, jogador.nome, jogador.vitorias, jogador.empates, jogador.derrotas);
        printf("\n");
        // fgetc(arquivo2);
    }

    printf("\n\n");
    fclose(arquivo2);
    getchar();
    printf(BOLD(YELLOW("\n  Digite qualquer tecla para continuar: ")));
    scanf("%c", &carac);
    system("clear");
    return;
}

// continua um jogo salvo
void continuarJogo(char nomeArquivo[])
{

    if (file_exists(nomeArquivo))
    {                       // verifica se o arquivo existe
        Jogo jogo;          // cria uma variável do struct jogo
        Jogador jog1, jog2; // cria duas variáveis do struct jogador

        // cria o tabuleiro
        char **tabela = criaTabela(); // cria uma tabela alocada dinamicamente
        char c;

        FILE *arquivo = fopen(nomeArquivo, "r"); // abre o arquivo no modo leitura

        fscanf(arquivo, "%d", &jogo.quantJogadores); // lê a primeira linha do arquivo (que é a quant de jogadores) e armazena
                                                     //  na variável quantJogadores
        c = fgetc(arquivo);
        fgets(jog1.nome, 50, arquivo); // pega o nome do jogador 1, sem fazer nenhuma verificação pois o jogo sempre vai ter pelo
                                       // menos um jogador
        jog1.nome[strlen(jog1.nome) - 1] = '\0'; // exclui o /n do final do nome

        if (jogo.quantJogadores == 2)
        { // verifica se a quantidade de jogadores no arquivo é igual a 2, se for pega o nome do
          //  jogador 2 e exclui o \n do final do nome
            fgets(jog2.nome, 50, arquivo);
            jog2.nome[strlen(jog2.nome) - 1] = '\0';
        }
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                c = fgetc(arquivo); // lê a parte da "tabela" que ta no arquivo

                if (c == 'X')
                {                       // se tiver um X no arquivo
                    tabela[i][j] = 'X'; // a tabela na mesma posição vai receber X
                }

                else if (c == 'O')
                {                       // se tiver um O no arquivo
                    tabela[i][j] = 'O'; // a tabela na mesma posição vai receber
                }
                else if (c == '-')
                {                       // se tiver um - no arquivo
                    tabela[i][j] = ' '; // a tabela na mesma posição vai receber um espaço em branco
                }

                c = fgetc(arquivo);
            }
            c = fgetc(arquivo);
        }

        fscanf(arquivo, "%d", &jogo.ultimaJogada); // lê quem fez a última jogada

        fclose(arquivo);

        if (jogo.quantJogadores == 1)
        { // se a quant de jogadores for 1 vai abrir a função realizar jogada 1,
          // responsável por fazer jogadas playerVSpc
            realizarJogada1(&tabela, 5, &jog1); // passa como parâmetro a tabela já macada, a flag com valor 5 para não inciar um
                                                //  novo jogo, e o nome do jogador 1
        }

        else
        { // se a quant de jogadores for 2 vai abrir a função realizar jogada 2,
          // responsável por fazer jogadas playerVSplayer
            realizarJogada2(&tabela, 5, &jog1, &jog2); // passa como parâmetro a tabela já macada, a flag com valor 5 para não inciar um
                                                       //  novo jogo, e o nome dos jogadores 1 e 2
        }
        char k;
        printf(BOLD(YELLOW("\nDigite qualquer tecla para continuar! ")));
        scanf("%c", &k);
        liberaTabela(tabela);
    }
    else
    { // caso o arquivo não exista retorna uma mensagem de erro
        printf(BOLD(RED("  Não existe um jogo salvo com esse nome!")));
    }
}
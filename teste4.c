#include <stdio.h>

#define TAM 5
#define TESOUROS 3

typedef struct
{
    char nome[30];
    int tentativas;
} Jogador;

void inicializarMapa(char mapa[TAM][TAM]);
void mostrarMapa(char mapa[TAM][TAM]);
void posicionarTesouros(char mapa[TAM][TAM]);
int procurarTesouro(char mapa[TAM][TAM], int *encontrados);
void salvarResultado(Jogador jogador);
void lerHistorico();

int main()
{
    char mapa[TAM][TAM];

    Jogador jogador;

    int encontrados = 0;

    jogador.tentativas = 0;

    printf("=================================\n");
    printf("       CACA AO TESOURO\n");
    printf("=================================\n\n");

    printf("Nome do jogador: ");
    scanf("%s", jogador.nome);

    inicializarMapa(mapa);

    posicionarTesouros(mapa);

    while(encontrados < TESOUROS)
    {
        mostrarMapa(mapa);

        if(procurarTesouro(mapa, &encontrados))
        {
            jogador.tentativas++;
        }

        printf("\nTesouros encontrados: %d/%d\n",
               encontrados,
               TESOUROS);
    }

    printf("\n=================================\n");
    printf("PARABENS!\n");
    printf("VOCE ENCONTROU TODOS OS TESOUROS!\n");
    printf("Tentativas realizadas: %d\n",
           jogador.tentativas);
    printf("=================================\n");

    salvarResultado(jogador);

    lerHistorico();

    return 0;
}

void inicializarMapa(char mapa[TAM][TAM])
{
    int i;
    int j;

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            mapa[i][j] = '~';
        }
    }
}

void mostrarMapa(char mapa[TAM][TAM])
{
    int i;
    int j;

    printf("\n");

    printf("   ");

    for(j = 0; j < TAM; j++)
    {
        printf("%d ", j);
    }

    printf("\n");

    for(i = 0; i < TAM; i++)
    {
        printf("%d  ", i);

        for(j = 0; j < TAM; j++)
        {
            printf("%c ", mapa[i][j]);
        }

        printf("\n");
    }
}

void posicionarTesouros(char mapa[TAM][TAM])
{
    mapa[0][3] = 'T';

    mapa[2][1] = 'T';

    mapa[4][4] = 'T';
}

int procurarTesouro(char mapa[TAM][TAM], int *encontrados)
{
    int linha;
    int coluna;

    printf("\nLinha: ");
    scanf("%d", &linha);

    printf("Coluna: ");
    scanf("%d", &coluna);

    if(linha < 0 || linha >= TAM ||
       coluna < 0 || coluna >= TAM)
    {
        printf("Posicao invalida!\n");
        return 0;
    }

    if(mapa[linha][coluna] == 'X' ||
       mapa[linha][coluna] == 'O')
    {
        printf("Posicao ja utilizada!\n");
        return 0;
    }

    if(mapa[linha][coluna] == 'T')
    {
        printf("\nTESOURO ENCONTRADO!\n");

        mapa[linha][coluna] = 'X';

        (*encontrados)++;

        return 1;
    }

    printf("\nNADA ENCONTRADO!\n");

    mapa[linha][coluna] = 'O';

    return 1;
}

void salvarResultado(Jogador jogador)
{
    FILE *arquivo;

    arquivo = fopen("historico_tesouro.txt", "a");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fprintf(
        arquivo,
        "%s %d\n",
        jogador.nome,
        jogador.tentativas
    );

    fclose(arquivo);

    printf("\nResultado salvo com sucesso!\n");
}

void lerHistorico()
{
    FILE *arquivo;

    char nome[30];
    int tentativas;

    arquivo = fopen("historico_tesouro.txt", "r");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("\n=================================\n");
    printf("          HISTORICO\n");
    printf("=================================\n");

    while(
        fscanf(
            arquivo,
            "%s %d",
            nome,
            &tentativas
        ) != EOF
    )
    {
        printf(
            "Jogador: %-15s Tentativas: %d\n",
            nome,
            tentativas
        );
    }

    fclose(arquivo);
}
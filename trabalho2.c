#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_INVENTARIO 20
#define VIDA_INICIAL 100
#define ATAQUE_INICIAL 10
#define DEFESA_INICIAL 5
#define OURO_INICIAL 50
#define XP_PARA_SUBIR_NIVEL 100

enum Itens {
    ITEM_VAZIO = 0,
    POCAO_PEQUENA = 1,
    POCAO_GRANDE = 2,
    ESPADA = 3,
    ARMADURA = 4,
    ESCUDO = 5
};

typedef struct {
    char nome[50];
    int vida;
    int vidaMaxima;
    int ataque;
    int defesa;
    int nivel;
    int experiencia;
    int ouro;
    int criado;
} Personagem;

typedef struct {
    char nome[30];
    int vida;
    int ataque;
    int recompensaXp;
    int recompensaOuro;
} Monstro;

void limparBuffer();
void pausar();
int lerOpcao();
void criarPersonagem(Personagem *heroi, int inventario[]);
void mostrarStatus(Personagem heroi);
void explorarMapa(Personagem *heroi, int inventario[]);
void combate(Personagem *heroi, Monstro monstro);
void subirNivel(Personagem *heroi);
void loja(Personagem *heroi, int inventario[]);
void menuInventario(Personagem *heroi, int inventario[]);
void visualizarInventario(int inventario[]);
void usarItem(Personagem *heroi, int inventario[]);
void descartarItem(int inventario[]);
void descansar(Personagem *heroi);
void chefeFinal(Personagem *heroi);
int adicionarItem(int inventario[], int item);
void removerItem(int inventario[], int posicao);
const char *nomeItem(int item);
int existePersonagem(Personagem heroi);
int personagemVivo(Personagem heroi);
int calcularDanoRecebido(Personagem heroi, int ataqueMonstro, int defendendo);

int main() {
    Personagem heroi;
    int inventario[TAM_INVENTARIO];
    int opcao;

    srand(time(NULL));

    heroi.criado = 0;
    for (int i = 0; i < TAM_INVENTARIO; i++) {
        inventario[i] = ITEM_VAZIO;
    }
	do {
        printf("\n=================================================\n");
        printf("        RPG DE TEXTO - A JORNADA DO HEROI        \n");
        printf("=================================================\n");
        printf("1 - Criar Personagem\n");
        printf("2 - Ver Status\n");
        printf("3 - Explorar Mapa\n");
        printf("4 - Loja\n");
        printf("5 - Inventario\n");
        printf("6 - Descansar\n");
        printf("7 - Enfrentar Chefe Final\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                criarPersonagem(&heroi, inventario);
                break;
            case 2:
                mostrarStatus(heroi);
                break;
            case 3:
                explorarMapa(&heroi, inventario);
                break;
            case 4:
                loja(&heroi, inventario);
                break;
            case 5:
                menuInventario(&heroi, inventario);
                break;
            case 6:
                descansar(&heroi);
                break;
            case 7:
                chefeFinal(&heroi);
                break;
            case 0:
                printf("\nSaindo do jogo... Ate a proxima aventura!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int lerOpcao() {
    int opcao;

    if (scanf("%d", &opcao) != 1) {
        limparBuffer();
        return -1;
    }

    limparBuffer();
    return opcao;
}

int existePersonagem(Personagem heroi) {
    if (!heroi.criado) {
        printf("\nCrie um personagem antes de acessar esta opcao.\n");
        return 0;
    }
    return 1;
}

int personagemVivo(Personagem heroi) {
    if (heroi.vida <= 0) {
        printf("\nSeu personagem esta sem vida. Crie um novo personagem para continuar.\n");
        return 0;
    }
    return 1;
}

void criarPersonagem(Personagem *heroi, int inventario[]) {
    printf("\nDigite o nome do heroi: ");
    fgets(heroi->nome, sizeof(heroi->nome), stdin);
    heroi->nome[strcspn(heroi->nome, "\n")] = '\0';

    if (strlen(heroi->nome) == 0) {
        strcpy(heroi->nome, "Heroi Sem Nome");
    }
 
    heroi->vida = VIDA_INICIAL;
    heroi->vidaMaxima = VIDA_INICIAL;
    heroi->ataque = ATAQUE_INICIAL;
    heroi->defesa = DEFESA_INICIAL;
    heroi->nivel = 1;
    heroi->experiencia = 0;
    heroi->ouro = OURO_INICIAL;
    heroi->criado = 1;

    for (int i = 0; i < TAM_INVENTARIO; i++) {
        inventario[i] = ITEM_VAZIO;
    }

    printf("\nPersonagem criado com sucesso!\n");
    printf("Bem-vindo ao reino de C-Nai, %s!\n", heroi->nome);
} 

void mostrarStatus(Personagem heroi) {
    if (!existePersonagem(heroi)) {
        return;
    }

    printf("\n================ STATUS DO HEROI ================\n");
    printf("Nome: %s\n", heroi.nome);
    printf("Vida: %d/%d\n", heroi.vida, heroi.vidaMaxima);
    printf("Ataque: %d\n", heroi.ataque);
    printf("Defesa: %d\n", heroi.defesa);
    printf("Nivel: %d\n", heroi.nivel);
    printf("Experiencia: %d\n", heroi.experiencia);
    printf("Ouro: %d\n", heroi.ouro);
}

void explorarMapa(Personagem *heroi, int inventario[]) {
    int evento;

    if (!existePersonagem(*heroi) || !personagemVivo(*heroi)) {
        return;
    }

    evento = rand() % 5 + 1;

    printf("\nVoce comeca a explorar uma regiao perigosa do reino de C-Nai...\n");

    if (evento == 1) {
        Monstro monstros[4] = {
            {"Goblin", 30, 5, 20, 15},
            {"Esqueleto", 50, 8, 35, 25},
            {"Orc", 80, 12, 55, 40},
            {"Lobisomem", 120, 15, 80, 60}
        };

        int indice = rand() % 4;
        printf("\nUm monstro apareceu: %s!\n", monstros[indice].nome);
        combate(heroi, monstros[indice]);
    } else if (evento == 2) {
        int ouroEncontrado = rand() % 41 + 10;
        heroi->ouro += ouroEncontrado;
        printf("\nVoce encontrou um bau!\n");
        printf("+%d moedas de ouro.\n", ouroEncontrado);
    } else if (evento == 3) {
        int item = (rand() % 2 == 0) ? POCAO_PEQUENA : POCAO_GRANDE;
        printf("\nVoce encontrou uma %s!\n", nomeItem(item));

        if (adicionarItem(inventario, item)) {
            printf("O item foi adicionado ao inventario.\n");
        } else {
            printf("Seu inventario esta cheio. O item foi perdido.\n");
        }
    } else if (evento == 4) {
        int dano = rand() % 21 + 10;
        heroi->vida -= dano;

        if (heroi->vida < 0) {
            heroi->vida = 0;
        }

        printf("\nVoce caiu em uma armadilha!\n");
        printf("Perdeu %d pontos de vida.\n", dano);

        if (heroi->vida <= 0) {
            printf("\nGAME OVER! O heroi nao resistiu aos ferimentos.\n");
        }
    } else {
        printf("\nNada aconteceu durante a exploracao.\n");
    }
}

void combate(Personagem *heroi, Monstro monstro) {
    int opcao;
    int danoRecebido;
    int fugiu = 0;

    printf("\n==================== COMBATE ====================\n");
    printf("Voce esta enfrentando: %s\n", monstro.nome);

    while (heroi->vida > 0 && monstro.vida > 0 && !fugiu) {
        printf("\n%s - Vida: %d/%d\n", heroi->nome, heroi->vida, heroi->vidaMaxima);
        printf("%s - Vida: %d\n", monstro.nome, monstro.vida);
        printf("\n1 - Atacar\n");
        printf("2 - Defender\n");
        printf("3 - Fugir\n");
        printf("Escolha: ");
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                monstro.vida -= heroi->ataque;
                printf("\nVoce atacou o %s e causou %d de dano.\n", monstro.nome, heroi->ataque);

                if (monstro.vida > 0) {
                    danoRecebido = calcularDanoRecebido(*heroi, monstro.ataque, 0);
                    heroi->vida -= danoRecebido;
                    printf("O %s atacou voce e causou %d de dano.\n", monstro.nome, danoRecebido);
                }
                break;

            case 2:
                danoRecebido = calcularDanoRecebido(*heroi, monstro.ataque, 1);
                heroi->vida -= danoRecebido;
                printf("\nVoce se defendeu!\n");
                printf("O %s atacou, mas voce recebeu apenas %d de dano.\n", monstro.nome, danoRecebido);
                break;

            case 3:
                if (rand() % 2 == 0) {
                    printf("\nVoce conseguiu fugir do combate!\n");
                    fugiu = 1;
                } else {
                    danoRecebido = calcularDanoRecebido(*heroi, monstro.ataque, 0);
                    heroi->vida -= danoRecebido;
                    printf("\nVoce tentou fugir, mas falhou!\n");
                    printf("O %s atacou voce e causou %d de dano.\n", monstro.nome, danoRecebido);
                }
                break;

            default:
                printf("\nOpcao invalida. Voce perdeu a vez!\n");
                danoRecebido = calcularDanoRecebido(*heroi, monstro.ataque, 0);
                heroi->vida -= danoRecebido;
                printf("O %s atacou voce e causou %d de dano.\n", monstro.nome, danoRecebido);
                break;
        }

        if (heroi->vida < 0) {
            heroi->vida = 0;
        }
    }

    if (heroi->vida <= 0) {
        printf("\nGAME OVER! Voce foi derrotado pelo %s.\n", monstro.nome);
    } else if (monstro.vida <= 0) {
        printf("\n%s derrotado!\n", monstro.nome);
        printf("+%d XP\n", monstro.recompensaXp);
        printf("+%d Ouro\n", monstro.recompensaOuro);

        heroi->experiencia += monstro.recompensaXp;
        heroi->ouro += monstro.recompensaOuro;
        subirNivel(heroi);
    }
}

int calcularDanoRecebido(Personagem heroi, int ataqueMonstro, int defendendo) {
    int dano = ataqueMonstro - heroi.defesa;

    if (dano < 1) {
        dano = 1;
    }

    if (defendendo) {
        dano = dano / 2;
        if (dano < 1) {
            dano = 1;
        }
    }

    return dano;
}

void subirNivel(Personagem *heroi) {
    while (heroi->experiencia >= XP_PARA_SUBIR_NIVEL) {
        heroi->experiencia -= XP_PARA_SUBIR_NIVEL;
        heroi->nivel++;
        heroi->ataque += 5;
        heroi->defesa += 3;
        heroi->vidaMaxima += 20;
        heroi->vida = heroi->vidaMaxima;

        printf("\nParabens! Voce subiu para o nivel %d.\n", heroi->nivel);
        printf("Ataque +5 | Defesa +3 | Vida Maxima +20\n");
        printf("Sua vida foi restaurada.\n");
    }
}

void loja(Personagem *heroi, int inventario[]) {
    int opcao;
    int item = ITEM_VAZIO;
    int preco = 0;

    if (!existePersonagem(*heroi) || !personagemVivo(*heroi)) {
        return;
    }

    do {
        printf("\n====================== LOJA =====================\n");
        printf("ouro atual: %d\n", heroi->ouro);
        printf("1 - Pocao Pequena - 20 ouro\n");
        printf("2 - Pocao Grande  - 40 ouro\n");
        printf("3 - Espada        - 100 ouro\n");
        printf("4 - Armadura      - 120 ouro\n");
        printf("5 - Escudo        - 80 ouro\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                item = POCAO_PEQUENA;
                preco = 20;
                break;
            case 2:
                item = POCAO_GRANDE;
                preco = 40;
                break;
            case 3:
                item = ESPADA;
                preco = 100;
                break;
            case 4:
                item = ARMADURA;
                preco = 120;
                break;
            case 5:
                item = ESCUDO;
                preco = 80;
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                continue;
            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        if (heroi->ouro < preco) {
            printf("\nOuro insuficiente para comprar %s.\n", nomeItem(item));
        } else if (!adicionarItem(inventario, item)) {
            printf("\nInventario cheio. Nao foi possivel comprar o item.\n");
        } else {
            heroi->ouro -= preco;
            printf("\nVoce comprou: %s.\n", nomeItem(item));
            printf("Ouro restante: %d\n", heroi->ouro);
        }
    }while (opcao != 0);
}

void menuInventario(Personagem *heroi, int inventario[]) {
    int opcao;

    if (!existePersonagem(*heroi)) {
        return;
    }

    do {
        printf("\n=================== INVENTARIO ==================\n");
        printf("1 - Visualizar Itens\n");
        printf("2 - Usar Item\n");
        printf("3 - Descartar Item\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                visualizarInventario(inventario);
                break;
            case 2:
                if (personagemVivo(*heroi)) {
                    usarItem(heroi, inventario);
                }
                break;
            case 3:
                descartarItem(inventario);
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
        }
    } while (opcao != 0);
}

void visualizarInventario(int inventario[]) {
    int vazio = 1;

    printf("\nItens no inventario:\n");

    for (int i = 0; i < TAM_INVENTARIO; i++) {
        if (inventario[i] != ITEM_VAZIO) {
            printf("%d - %s\n", i + 1, nomeItem(inventario[i]));
            vazio = 0;
        }
    }

    if (vazio) {
        printf("Inventario vazio.\n");
    }
}

void usarItem(Personagem *heroi, int inventario[]) {
    int posicao;
    int item;

    visualizarInventario(inventario);

    printf("\nDigite a posicao do item que deseja usar: ");
    posicao = lerOpcao();
    posicao--;

    if (posicao < 0 || posicao >= TAM_INVENTARIO || inventario[posicao] == ITEM_VAZIO) {
        printf("\nItem invalido.\n");
        return;
    }

    item = inventario[posicao];

    switch (item) {
        case POCAO_PEQUENA:
            heroi->vida += 20;
            if (heroi->vida > heroi->vidaMaxima) {
                heroi->vida = heroi->vidaMaxima;
            }
            printf("\nVoce usou uma Pocao Pequena e recuperou vida.\n");
            removerItem(inventario, posicao);
            break;

        case POCAO_GRANDE:
            heroi->vida += 50;
            if (heroi->vida > heroi->vidaMaxima) {
                heroi->vida = heroi->vidaMaxima;
            }
            printf("\nVoce usou uma Pocao Grande e recuperou vida.\n");
            removerItem(inventario, posicao);
            break;

        case ESPADA:
            heroi->ataque += 5;
            printf("\nVoce equipou uma Espada. Ataque +5.\n");
            removerItem(inventario, posicao);
            break;

        case ARMADURA:
            heroi->defesa += 5;
            printf("\nVoce equipou uma Armadura. Defesa +5.\n");
            removerItem(inventario, posicao);
            break;

        case ESCUDO:
            heroi->defesa += 3;
            printf("\nVoce equipou um Escudo. Defesa +3.\n");
            removerItem(inventario, posicao);
            break;

        default:
            printf("\nEste item nao pode ser usado.\n");
            break;
    }
}

void descartarItem(int inventario[]) {
    int posicao;

    visualizarInventario(inventario);

    printf("\nDigite a posicao do item que deseja descartar: ");
    posicao = lerOpcao();
    posicao--;

    if (posicao < 0 || posicao >= TAM_INVENTARIO || inventario[posicao] == ITEM_VAZIO) {
        printf("\nItem invalido.\n");
        return;
    }

    printf("\nVoce descartou: %s.\n", nomeItem(inventario[posicao]));
    removerItem(inventario, posicao);
}

void descansar(Personagem *heroi) {
    int vidaAntes;

    if (!existePersonagem(*heroi) || !personagemVivo(*heroi)) {
        return;
    }

    vidaAntes = heroi->vida;
    heroi->vida += 30;

    if (heroi->vida > heroi->vidaMaxima) {
        heroi->vida = heroi->vidaMaxima;
    }

  printf("\nVoce descansou em seguranca.\n");
    printf("Vida antes: %d\n", vidaAntes);
    printf("Vida atual: %d/%d\n", heroi->vida, heroi->vidaMaxima);
}

void chefeFinal(Personagem *heroi) {
    Monstro dragao = {"Dragao das Sombras", 300, 25, 200, 300};

    if (!existePersonagem(*heroi) || !personagemVivo(*heroi)) {
        return;
    }

    if (heroi->nivel < 5) {
        printf("\nVoce ainda nao esta preparado para enfrentar o Dragao.\n");
        printf("Nivel necessario: 5 | Seu nivel: %d\n", heroi->nivel);
        return;
    }

    printf("\nO Dragao das Sombras surge diante de voce!\n");
    printf("Esta e a batalha final pelo destino do reino de C-Nai.\n");

    combate(heroi, dragao);

    if (heroi->vida > 0) {
        printf("\n=================================================\n");
        printf("PARABENS! VOCE DERROTOU O DRAGAO DAS SOMBRAS!\n");
        printf("O reino de C-Nai foi salvo pelo heroi %s.\n", heroi->nome);
        printf("=================================================\n");
    }
}

int adicionarItem(int inventario[], int item) {
    for (int i = 0; i < TAM_INVENTARIO; i++) {
        if (inventario[i] == ITEM_VAZIO) {
            inventario[i] = item;
            return 1;
        }
    }

    return 0;
}

void removerItem(int inventario[], int posicao) {
    if (posicao < 0 || posicao >= TAM_INVENTARIO) {
        return;
    }

    for (int i = posicao; i < TAM_INVENTARIO - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    inventario[TAM_INVENTARIO - 1] = ITEM_VAZIO;
}

const char *nomeItem(int item) {
    switch (item) {
        case POCAO_PEQUENA:
            return "Pocao Pequena";
        case POCAO_GRANDE:
            return "Pocao Grande";
        case ESPADA:
            return "Espada";
        case ARMADURA:
            return "Armadura";
        case ESCUDO:
            return "Escudo";
        default:
            return "Item Vazio";
    }
}

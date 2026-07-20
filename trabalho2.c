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
	
printf("\n===================================================================\n");

printf("rpg de texto a jornada do heroi\n");

printf("1 criar personagem\n");

printf("2 ver status\n");

printf("3 explorar mapa\n");

printf("4 loja\n");

printf("5 inventario\n");

printf("6 descansar\n");

printf("7 enfrentar chefe final\n");

printf("0 sair\n");

printf("escolha:");

	opcao = leropcao();
	
switch (opcao)

{
case 1:

criarpersonagem(&heroi,inventario);

break;

case 2:

mostrarstatus(heroi);

break;

case 3:

explorarmapa(&heroi,inventario);

break;

case 4:

loja(&heroi,inventario);

break;

case 5:

menuinventario(&heroi,inventario);

break;

case 6:

descansar(&heroi);

break;

case 7:

chefefinal(&heroi);

break;

case 0:

printf("\nsaindo do jogo...ate a proxima aventura!\n);

break;

default:

printf("\n opcao invalida.tente novamente.\n");

break;

}

	}
	
	while(opcao!=0);
	
	return 0;
	
}

void limparbuffer(){
	
}
}

void pausar ()
{
	
	printf("\n pressione enter para continuar...")
	
	getchar();
	
}
	
int leropcao (){
	
	int opcao; 
	
	if(scanf("%d"&opcao)!= 1){ 
	
	limparbuffer();
	
	return-1;
	
	}
	
limparbuffer();

return opcao;

}

int existepersonagem(personagem heroi){

if(!heroi.criado){
	
printf("\n crie um personagem antes de acessar esta opcao.\n);

return 0;

}

return 1;
}

int personagemvivo (personagemheroi){

if(heroi . vida<= 0){
	
	printf("\n seu personagem esta sem vida. crie um novo personagem para continuar.\n");

return 0;	

}

return 1;

}


void criarpersonagem (personagem*heroi,int inventario[])

{
	
	printf("\n digite o nome do heroi:");
	
	fgets (heroi->nome,sizeof(heroi->nome),stdin),heroi->nome[strcspn(heroi->,"\n")] = '\0'\;
	
	if(strlen(heroi->nome)==0){
		
		strcpy(heroi->nome,"heroi sem nome");
		
heroi->vida = vida_incial;

heroi->vidamaxima = vida_inicial;

heroi->ataque = ataque_inicial;

heroi->defesa = defesa_inicial;

heroi->nivel = 1;

heroi->experiencia = 0;

heroi->ouro = ouro_inicial;

heroi->criado = 1;

for(int i =  0;i<tam_inventario;i++)(inventario[i] = item_vazio;

	}
	
	printf("n\ personagem criado com sucesso!\n");
	
	printf("bem vindo au reino de C-NAI,%s!\n",heroi->nome);
	
}

void mostrarstatus(personagem heroi){
	
	if(!existepersonagem(heroi))
}
return;
}
printf("\n=====status do heroi==================\n");

printf("nome:%s\n",heroi.nome);

printf("vida:%d/%d\n",heroi.vida,heroi.vidamaxima);

printf("ataque:%d\n",heroi.ataque);
printf("defesa:%d\n",heroi.defesa);
printf("nivel:%d\n",heroi.nivel);
printf("experiencia:%d\n",heroi.experiencia);
printf("ouro:%d\n",heroi.ouro);
}
void explorarmapa(personagem*heroi,int inventario[]){
	int evento;
	if(!existepersonagem(*heroi)||!personagemvivo(*heroi)){
		return;
	}
	evento = rand ()%5+1;
	printf("\nvc comeca a explorar uma regiao perigosa do reino de C-NAI...\n");
	if(evento ==  1){
		{"goblin",30,5,20,15},
			{"esqueleto",50,8,35,25},
				{"orc",80,12,,55,40},
					{"lobisomem",120,15,80,60}
	};
	int indice = rand()%4;printf("\n um monstro apareceu:%s!\n",monstros[indice].nome);
	combate(heroi,monstros[indice]);
}
else if(evento == 2){
	int ouroencontrado = rand()%41+10;
	heroi->ouro += ouroencontrado;
printf("\n vc encontrou  um bau!\n");
printf("+%d moedas de ouro\n",ouroencontrado);
}
else if(evento == 3){
	int item = (rand()% 2 == 0)? pocao_pequena : pocao_grande;
	printf("\n vc encontrou uma %s!\n",nomeitem(item));
	if(adicionaritem(inventario,item)){
printf("item foi adicionado ao inventario\n");
	}
	else{
printf("seu inventario esta cheio.o item foi perdido.\n");
	}
}
else if (evento == 4){
int dano = rand() % 21+10;
heroi->vida-=dano;
if(heroi-> <0){
heroi->vida = 0;}
printf("\n vc caiu em uma armadilha !\n");
printf("perdeu %d pontos de vida \n");
if (heroi->vida<= 0)
}
printf("\n Game over! o heroi nao resistiu aos ferimentos\n");
}
}else {
	printf ("\n nada aconteceu durante a exploracao\n");
}
}
void combate(personagem*heroi,monstro monstro)
{
	int opcao;
	int danorecebido;
	int fugiu = 0 ;
	printf ("\n===============combate=========\n");
	printf ("vc esta enfrentando:%s\n",monstro.nome);
while(heroi->vida>0&&monstro.vida>0&&!fugiu){
	printf("\n%s-vida:%d\%d\n",heroi->nome,heroi->,heroi->vidamaxima);
	printf("%s-vida:%d\n",monstro.nome,monstro.vida);
	printf("\n1 - atacar\n");
	printf("2 - defender\n");
	printf("3 - fugir\n");
	printf("escolha:");
	opcao = leropcao();
	switch (opcao) {
		case 1:
		monstro.vida-=heroi->ataque;
		printf("\n vc atacou o %s e causou %d de dano.\n",monstro.nome,heroi->ataque);
		if(monstro.vida>0){
			danorecebido = calculardanorecebido(*heroi,monstro.ataque,0);
			heroi->vida-= danorecebido;
			printf("o %s atacou vc e causou %d de dano.\nn",monstro.nome,danorecebido);
		}
		break;
		case 2:
		danorecebido = calculardanorecebido(*heroi,monstro.ataque,1);
		heroi->vida-=danorecebido;
		printf("\n vc defendeu!\n");
		printf("o %s atacou, mas vc recebeu apenas %d de dano.\n",monstro.nome,danorecebido);
		break;
		case 3:
		if (rand()%2==0){
			printf("\n vc conseguiu fugir do combate\n");
			fugiu = 1;
		}else{
			danorecebido = calculardanorecebido(*heroi,monstro.ataque,0);
			heroi->vida-=danorecebido;
			printf("\n vc tentou fugir mas falhou!\n");
			printf("o %s atacou vc e causou %d de dano.\n",monstro.nome, danorecebido)
		}
		break;
	
default:
printf("\n opcao invalida vc perdeu a vez\n");
danorecebido = caculardanorecebido(*heroi,monstro.ataque,0);
 heroi->vida -= danorecebido;
 printf("o %s atacou vc  causou %d dano\n",monstro.nome,danorecebido);
	break;}
}
if(heroi->vida<0){
heroi->vida = 0;}
}
if(heroi->vida<=0){
	printf("\n !GAME OVER! vc foi derrotado pelo %s.\n",monstro.nome);
}
else if (monstro.vida<=0){
	printf("\n%s !derrotado!\n",monstro.nome);
	printf("+% XP\n",monstro.recompensaxp);
	printf("+%d ouro\n",monstro.recompensaouro");
    heroi->experiencia +=monstro.recompensaxp;
	heroi->ouro + = monstro.recompensaouro;subirnivel(heroi);
}
}
int calculardanorecebido(personagem heroi,int ataquemonstro,int defendendo);
{
	int dano =ataquemonstro-heroi.defesa;
	if(dano<1){
	dano = 1;
	}
	if (defendendo){
		dano = dano /2;
	if (dano < 1){
	dano = 1 ;
	}
    }
	return dano;
}
void subirnivel(personagem*heroi){
	while(hero->=experiencia>=xp_para_subir_nivel){
		heroi->experiencia -=xp_para_subir_nivel;
		heroi->nivel++;
		heroi->ataque += 5;
		heroi->defesa += 3;
		heroi->vidamaxima;
		printf("\nParabens!Voce subiu para o nivel %d.\n",heroi->nivel);
		printf("ataque +5|defesa +3|vida maxima +20\n");
		printf("sua vida foi restaurada.\n");
	}
}
void loja (personagem*heroi,int inventario[]){
	int opcao;
	int item = item_vazio;
int preso = 0;
if(!existepersonagem(*heroi)||!personagemvivo(*heroi)){return;
}
do {
printf("\n ====================================loja==================\n");
printf("ouro atual:%d\n",heroi->ouro);
itf("1 - pocao pequena -20 ouro\n");
printf("2 - pocao grande -40 ouro\n");
printf("3 - espada - 100 ouro\n");
printf("4 - armadura  - 120 ouro\n");;
printf("5 - escudo - 80 ouro\n");
printf("0 - voltar\n");
printf("escolha:");
opcao = leropcao();
swich (opcao)}
case 1:
item = pocao_pequena;
preco = 20;
break;
case 2 : 
item  = pocao_grande;
preco = 40;  
break;
case 3 :
item = espada ;
preco = 100;
break;
case 4 :
item = armadura;
preco = 120;
break;
case 5 :
item = escudo;
preco = 80;
break;
case 0;
printf("\nvoltando ao menu principal\n");
continue;
defaut: 
print("\nopcao invalida\n");
continue;
}
if(heroi->ouro<preco){
printf("\nouro insuficiente para comprar%s.\n",nomeitem(item));
}else if(!adicionar item(inventario,item)){
printf("\ninventario cheio.Nao foi possivel comprar o item .\n");
}else{
heroi->ouro-=preco;
printf("\nvc comprou:%s.\n",nomeitem(item));
	printf("ouro restante:%d\n",heroi->ouro);
}
}while(opcao!=0);
}
void menuinventario(personagem*heroi,int inventario[]){
int opcao;
if(!existepersonagem(*heroi)){
return;
}
do{
printf("\n-----------------------------------------------------------------------inventario=======================\n");

printf("1 - visualizar itens\n");
printf("2 - usar item \n");
printf("3 - descartar item\n"
printf(" 0 - voltar\n");
printf("escolha:");
opcao = leropcao();

swich(opcao){
	
	case1: 
	visualizarinventario(inventario);
	break;
	case 2:
	if(personagemvivo(*heroi)){
		usaritem(heroi,inventario);
	}
	break;
	case 3:
	descartaritem(inventario);
	break;
	case 0:
	printf("\nvoltando ao mundo principal...\n");
	break;
	default:
	printf(\n"opcao invaild.\n");
	break;
}
}while(opcao!=0);
}
void visualizar inventario(int inventario:[]){int vazio = 1;
for(int i = 0; <tam_inventario;i++){
	if(inventario[i]!=item_vazio){
		printf(%d-%s\n",i+1,
		nomeitem(inventario[1]));
		vazio = 0;
	}
}
if (vazio){
	printf("inventario vazio.\n");
}
}
if(vazio){
	printf("inventario vazio".\n);
}
}
void usaritem(personagem,*heroi,int,invenatrio[]){
	int posicao;
	int item;
	printf("\ndigite a posicao do item que deseja usar:");
	posicao = leropcao();
	posicao--;
	if(posicao< 0||posicao>=tam_inventario||inventario[posicao]==item_vazio{
	printf("\nitem invalido.\n");
return;
	}
item= inventario[posicao];
switch(item){
	case pocao_pequena:
	heroi-> vida+=20;
	if(heroi->vida>heroi->vidamaxima){
		heroi->vida=heroi->vidamaxima;
	}
	printf("\nvc usou uma pocao pequena e recuperou vida.\n");
	removeritem(inventario,posicao);
	break;
	
	case pocao_grande:
	heroi->vida+=50;
	if(heroi->vida>heroi->vidamaxima){
		heroi->vida=heroi->vidamaxima;
	}
	printf("\nvc usou uma pocao grande e  recuperou vida.\n");
	removeritem(intentario,posicao);
	break;
	
	case espada:
	heroi->ataque+=5;
	printf("\nvc equipou uma espada.ataque+5.\n");
	removerintem(intario,posicao);
	break;
	
	case armadura:
	heroi->defesa +=5;
	printf("\nvc equipou uma armadura defesa + 5.\n");
	removeritem(inventario,posicao);
	break;
	
	case escudo:
	heroi->defesa +=3;
	printf("\nvc equipou um escudo. defesa+3\n");
	removeritem(inventario,posicao);
	break;
	default;
	printf("\n este item nao pode ser usado.\n");
	break;
}
}
void descartaitem(int inventario[]){
	int posicao;
	visualizarinventario(inventario);
	printf("\ndigite a posicao do item que deseja descartar.");
	posicao=leropcao();
	posicao--;
	if(posicao<0||posicao.=tam_inventario||inventario[posicao]==item_vazio){
		printf("\nitem invalido.\n");
		return;
	}
printf("\nvc descartou :%s.\n",nomeitem(inventario[posicao](inventario[posicao]));
removeritem(inventario,posicao);
}
void descansar(personagem=*heroi){
	int vidaantes;
	if(!existepersonagem(*heroi)||!
	personagemvivo(*heroi)){
		return;
	}
	vidantes=heroi->vida;
	heroi->vida +=30;
 if(heroi->vida>heroi->vidamaxima){
heroi->=heroi->vidamaxima;
 }
 printf(\n"vc descansou em seguranca.\n");
 printf("vida antes:%d\n",vidaantes);
 printf("vida atual:%d\%d\n",heroi->vida heroi->vida maxima);
}
void chefefinal(personagem*heroi){
monstro dragon = ("dragon das sombras" ,300,25,200,300};
if(!existepersonagem(*heroi)||!
personagemvivo(*heroi){
	return;
}
if(heroi->nivel<5){
	printf(\n"vc ainda nao esta preparado paa enfrentar o drafon.\n");
	printf("nivel necessario:5|seu nivel:%d\n",heroi->nivel);
	return;
}
printf(\n"o dragon das sombras surge diante de vc!\n");
printf("esta e a batalha final pelo destino do reino de c-nai.\n");
combate(heroi,dragon);
if(heroi->vida>0){
	
	printf("\n===============================================================\n");
	printf("PARABENS!VC DERROTOU O DRAGON DAS SOMBRAS!\n");
	printf("o reino de c-nai foi salvo pelo heroi%s.\n",heroi->nome);
	printf("============================================================================================================================================\n");
}
 }
 int adicionaritem(int inventario[],int item){
	 for(int i = 0;i<tam_inventario;i++){
		 if(inventario[i]==item_vazio){
			 inventario[i]=item;
			 
			 return 1;
		 }
		 
	 }
	 return 0;
 }
 void removeritem(item inventario[],int posicao) {
	 if(posicao<0||posicao>==tam_inventario)
	 {
		 return;
	 }
	 for(int=posicao;i<tam_invenatrio-1;i++){
	 inventario[i]=inventario[i+1];
	 }
	 inventario[tam_inventario-1]= item_vazio;
 }
 const char *nomeitem(int item){
	 swich(item){
		 case pocao_pequena:
		 return"pocao pequena";
		  
		  const char*nomeitem(int item){
			  swich(item){
				  case pocao_pequena:
				  return"pocao pequena";
				  case pocao_grande:
				  return "pocao_grande";
				  case espada:
				  return "espada";
				  case armadura:
				  return "armadura";
				  case escudo:
				  return"escudo";
				  default:
				  
				  return"item vazio";
			  }
		  }
		 
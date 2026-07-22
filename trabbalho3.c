#include<stdio.h>

int main()
{
	// criando a variável ponteiro para o arquivo
	FILE *pont_arq;
	char palavra[20];
	double idade = 0.0;
	double total = 0.0;
	
  
	//abrindo o arquivo
	pont_arq = fopen("arquivo.txt", "a");
	
	if (pont_arq == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso!\n");

		for(int i = 0; i < 2; i++)
		{
			printf("Escreva seu nome:\n");
			scanf("%s", palavra);
			printf("Escreva sua idade\n");
			scanf("%lf",&idade);
			//usando fprintf para armazenar a string no arquivo
			fprintf(pont_arq, "%s\n%lf\n", palavra,idade);
		
		}
		
	}
	
	// fechando arquivo
	fclose(pont_arq);

	//abrindo o arquivo
	pont_arq = fopen("arquivo.txt", "r");
	
	if (pont_arq == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso!\n");
		printf("Pessoas Cadastradas:\n");
		//usando fscanf para ler os dados do arquivo
		for(int i = 0; i < 2; i++)
		{
			fscanf(pont_arq,"%s %lf",palavra,&idade);
			printf("%s\n %lf\n",palavra,idade);
			
		}
		
	}
		// fechando arquivo
	fclose(pont_arq);
 
  return(0);
}
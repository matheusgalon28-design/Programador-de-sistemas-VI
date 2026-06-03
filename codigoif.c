#include<stdio.h>

int main()
{
	int numero = 0;
	
	printf("Informe um numero:\n");
	scanf("%d",&numero);
	if(numero >5)
	{
		printf("numero é maior que 5\n");
	}
	else
	{
		printf("numero é menor que 5\n");
	}
	return(0);
}
#include<stdio.h>

void menu();
double soma(double a, double b);
double subtracao(double a, double b);
double multiplicacao(double a, double b);	
double divisao(double a, double b);	
	
int main()
{
	int opcao = 0;
	double result = 0.0;	
	double a = 0.0;
	double b = 0.0;

	do{
		menu();
		scanf("%d",&opcao);

	switch(opcao)
	{
	case 1:
		printf("informe os numeros que deseja realizar a operacao:\n");
		scanf("%lf",&a);
		printf("informe outro numero\n");
		scanf("%lf",&b);
		result = soma(a,b);
		printf("O resuldado e:%.2lf\n",result);
	break;
	case 2:
		printf("informe os numeros que deseja realizar a operacao:\n");
		scanf("%lf",&a);
		printf("informe outro numero\n");
		scanf("%lf",&b);
		result = subtracao(a,b);
		printf("o resultado e:%.2lf\n",result);
	break;
	case 3:
		printf("informe os numeros que deseja realizar a operacao:\n");
		scanf("%lf",&a);
		printf("informe outro numro\n");
		scanf("%lf",&b);
		result = multiplicacao(a,b);
		printf("O resultado e:%.2lf\n",result);
	break;
	case 4 :
		printf("informe os numeros que deseja realizar a operacao:\n");
		scanf("%lf",&a);
		printf("imforme outro nume\n");
		scanf("%lf",&b);
		if(b==0)
		{
			printf("Nao e posivel realizar a divisao por 0\n");
		}
		else
		{
			result = divisao(a,b);
			printf("O resultado e:%.2lf\n",result);
		}
	break;
		default:
			printf("informe uma opcao valida\n");
	}
		
	}while(opcao != 2);

	printf("Obrigado por usar a calculadora super poderosa caseira\n");
	return(0);
}

void menu()
{

printf("Escolha uma opcao abaixo\n");
printf("coloque seu nome--------------------------------\n");
printf("BEM VINDO A CALCULADORA 1.0\n");
printf("escolha uma opcao-------------------------------\n");
printf(" 1  opcao soma----------------------------------\n");
printf(" 2  opcao subtracao-----------------------------\n");
printf(" 3 opcao multplicacao---------------------------\n");
printf(" 4  opcao divisao------------------------------\n");
printf(" 5  opcao sair  -------------------------------\n");
}
double soma(double a, double b)
{
	return(a+b);
}

double subtracao(double a, double b)       
{
	return(a-b);
}

double multiplicacao (double a, double b)
{
	return(a*b);
}

double divisao(double a, double b)
{
	return(a/b);
}
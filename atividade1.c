#include <stdio.h>
int main ()
{
	int matriz[3][3];
	int j;	
	int i;
	for(int i = 0; i < 3;i++)
	{
		for(int j = 0; j < 3;j++)
		{
	
	printf("digite o valor da posicao [%d][%d]:",i,j);
    scanf("%d",&matriz[i][j]);
		}
	}
printf("\n matriz:\n");
	for(i = 0;i<3;i++){
    for(j = 0 ;j<3;j++){
	printf("%4d",matriz[i][j]);
	}
printf("\n");
	}
	return 0;
}

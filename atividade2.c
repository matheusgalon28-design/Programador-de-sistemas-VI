#include<stdio.h>
int main()
{
	int matriz[4][4];
	int i,j;
	int soma =0;
	for(i = 0;i<4;i++)
	{
		for( = 0;j<4;j++)
		{   
			scanf("%d",&matriz[i][j]);	
			soma += matriz[i][j];
		}
	}
	printf("soma total= %d\n",soma);
	return 0;
}

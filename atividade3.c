#include <stdio.h>
 int main ()
{ 
	 int matriz[5][5];

	int i,j;
	
	int maior = -9999,menor = 9999;
	
	int linhamaior,colunamaior;
	
		int linhamenor,colunamenor;
	for(i=0 ;i<5;i++){
		for(j=;j<5;j++){
	scanf("%d",&matriz[i][j]);
   if(matriz[i][j]>maior){	
    maior=matriz[i][j]; 
    linhamaior=i;
    colunamaior=j;
}
   if(matriz[i][j]<menor){
	 menor=matriz[i][j];
	 linhamenor=i;
	 colunamenor=j;
	}
	}
	}
	printf("maior valor:%d\n",maior);
	 printf("posicao:[%d][%d]\n",linhamaior,colunamaior);
	 printf("posicao:[%d][%d]\n",linhamenor,colunamenor);
	 
	 printf("menor valor:%d\n",menor);
	return 0;
}
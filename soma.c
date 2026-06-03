#include<stdio.h>

int main()
{
 int num=0;
 int num_2 = 0;
 int resp=0;
 
 resp=num+num_2 ;
 printf("informe um valor que deseja somar\n");
 scanf("%d",&num);
 printf("informe um outro valor que deseja somar\n");
 scanf("%d",&num_2);
 resp= num+num_2;
 
 printf("O RESULTADO E :%d\n", resp);
 
 return(0);
 
 }

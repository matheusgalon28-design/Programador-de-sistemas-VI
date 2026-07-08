#include<stdio.h>
int main()
{
int* ptr;
int valor = 50; 
ptr = &valor;
printf("endereco = % x\n",&valor);
printf("endereco = % x\n",ptr);
printf("endereco = % d\n",*ptr);
return(0);
}
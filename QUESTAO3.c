#include<stdio.h>
int main()
{
int *ptr;
int valor = 8; 
ptr = &valor;
printf("endereco = % d\n",*ptr);
*ptr *= 2;
printf("endereco = % d\n",*ptr);
return(0);
}
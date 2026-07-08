#include<stdio.h>
int main()
{
int *ptr;
int valor = 20; 
ptr = &valor;
printf("endereco = % d\n",*ptr);
*ptr += 5;
printf("endereco = % d\n",*ptr);
return(0);
}
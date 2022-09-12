#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	// int teste;

	// printa character
	char c = 'a';
	ft_printf("ft_printf = %c\n", c);

	//printa string
	char *d;
	d = "teste";
	ft_printf("ft_printf = %s\n",d);

	//printa inteiro
	int i;
	i = 123456789;
	ft_printf("ft_printf = %d\n", i);


	//printa unsigned inteiro
	int ui;
	ui = 2;
	ft_printf("ft_printf = %u\n", ui);
	printf("resposta esperada = %u\n", ui);

	//printa pointer
	long int *p;
	p = NULL;
	ft_printf("ft_printf = %p\n", p);
	printf("resposta esperada = %p\n", p);

	//printa hexadecimal x
	int x;
	x = 1500;
	ft_printf("ft_printf = %x\n", x);
	printf("resposta esperada = %x\n", x);

	// printa hexadecimal X
	int X;
	X = 99999;
	ft_printf("ft_printf = %X\n", X);
	printf("resposta esperada = %X\n", X);

	//printa mix
	ft_printf("as respostas foram: %c, %s, %d, %u, %p, %x, %X\n", c, d, i, ui, p,x, X);

return(0);
}

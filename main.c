#include "main.h"
#include <stdio.h>
/**
 * main - funcion tester
 *
 * Return: test
 */
int main(void)
{
	int len = 0;

	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	_printf("%%--------------------------------------------\n\n");
	printf("%\n");
	_printf("%");
	len = _printf("Let's try to printf a simple sentence.\n");
	return (len);
}

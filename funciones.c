#include <unistd.h>
#include "main.h"
/**
 * print_char - printea 1 caracter
 *
 * @args: son los argumentos que pasan de tipo char
 *
 * Return: un caracter impreso
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * print_string - funcion para calcular el largo del string y printearlo
 *
 * @args: son los argumentos que pasan de tipo string
 *
 * Return: largo del string y printeado
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int largo = 0;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[largo] != '\0')
	{
		largo++;
	}
	return (write(1, str, largo));
}
/**
 * print_percent - printea %
 *
 * @args: son los argumentos que te pasan que sean %
 *
 * Return: %
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
/**
 * print_int - printea un entero
 *
 * @args: son los argumentos que pasan de tipo int
 *
 * Return: largo del entero y printearlo
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0, div = 1;
	char digit;

	if (num == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		digit = '0' + (num / div);
		count += write(1, &digit, 1);
		num %= div;
		div /= 10;
	}
	return (count);
}

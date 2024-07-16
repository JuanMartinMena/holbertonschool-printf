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

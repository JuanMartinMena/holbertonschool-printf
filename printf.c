#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
 * _printf - funcion que printea los argumentos de tipo string/char
 *
 * @format: argumentos
 *
 * Return: retorna un int con la cantidad de veces que se imprime un caracter
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			for (j = 0; opciones[j].especificador; j++)
			{
				if (format[i] == opciones[j].especificador)
				{
					count += opciones[j].func(args);
					break;
				}
			}
			if (opciones[j].especificador == '\0')
			{
				write(1, "%", 1);
				count++;
				write(1, &format[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

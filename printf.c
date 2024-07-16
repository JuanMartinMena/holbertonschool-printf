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
	int i = 0, count = 0, (*func)(va_list);
	char especificador;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			especificador = format[i];
			if (especificador == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				func = choose_one(especificador);
				if (func != NULL)
					count += func(args);
				else
				{
					write(1, "%", 1);
					write(1, &especificador, 1);
					count += 2;
				}
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

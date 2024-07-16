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
	int i = 0, count = 0;
	char especificador;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			especificador = format[i];
			func = choose_one(especificador);

			if (func != NULL)
				count += func(args);
			else
			{
				write(1, "%", 1);
				count++;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			write(1, "%", 1);
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
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

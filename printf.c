#include "main.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

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

	if ((format != NULL && format[i] == '\0') || (format == NULL))
		return (-1);
	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
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
					count += percent_null(especificador, &count);
			}
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (count);
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
/**
 * percent_null - funcion que analiza el caso de que func sea NULL
 * @especificador: dato que se analiza como caso
 * @count: contador
 * Return: printea el especificador sea distinto a las opciones
 */
int percent_null(char especificador, int *count)
{
	write(1, "%", 1);
	write(1, &especificador, 1);
	*count += 2;
	return (0);
}

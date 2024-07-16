#include "main.h"
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;
	struct formato opciones[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	if (format == NULL)
		return (count);
	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
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
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				count += 2;
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

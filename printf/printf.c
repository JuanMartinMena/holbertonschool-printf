#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;
	formato opciones[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	if (format == NULL)
		return (count);
	va_start(args, format);
	while (format != NULL && format[i] != NULL)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			for
				//falta poner para que interprete cada letra despues del % como una funcion (siempre y cuando este definida)

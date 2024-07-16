#include "main.h"
/**
 * opciones - estructura que evalua caracteres y les asigna una funcion
 *
 */
int (*choose_one(char especificador))(va_list)
{
	int i = 0;

	form opciones[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	while (opciones[i].especificador != '\0')
	{
		if (opciones[i].especificador == especificador)
			return opciones[i].func;
		i++;
	}
	return (NULL);
}

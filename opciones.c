#include "main.h"
/**
 * choose_one - Le llega la info del argumento y lo testa ante los casos
 * @especificador: el caracter que le psan a la funcion choose_one
 * Return: caso
 */
int (*choose_one(char especificador))(va_list)
{
	int i = 0;

	form opciones[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

	while (opciones[i].especificador != '\0')
	{
		if (opciones[i].especificador == especificador)
			return (opciones[i].func);
		i++;
	}
	return (NULL);
}

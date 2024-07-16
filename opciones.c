#include "main.h"
/**
 * struct formato - estructura que evalua caracteres y les asigna una funcion
 *
 * @opciones: es el nombre del array de las estructuras tipo formato
 */
struct formato opciones[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'\0', NULL}
};

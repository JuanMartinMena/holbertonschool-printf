#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * formato - estructura para identificar que funcion usar
 *
 * @especificador: caracter propio de cada funcion
 * @func: puntero a funcion de tipo va_list que devuelve un entero
 */
struct formato {
	char especificador;
	int (*func)(va_list);
};

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args); int print_percent(va_list args);

#endif

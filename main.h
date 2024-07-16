#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
/**
 * struct formato - estructura para identificar que funcion usar
 *
 * @especificador: caracter propio de cada funcion
 * @func: puntero a funcion de tipo va_list que devuelve un entero
 */
typedef struct formato
{
	char especificador;
	int (*func)(va_list);
} form;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int percent_null(char especificador, int *count);

int (*choose_one(char especificador))(va_list);

#endif

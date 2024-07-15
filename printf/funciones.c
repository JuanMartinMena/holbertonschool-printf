#include <unistd.h>
#include "main.h"

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return write(1, &c, 1);
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int largo = 0;

	if (str == NULL)
	{
		return (largo);
	}
	while (str[largo] != '\0')
	{
		largo++;
	}
	return write(1, str, len);
}
int print_percent(va_list args)
{
	(void)args;
	return write(1, "%", 1);
}

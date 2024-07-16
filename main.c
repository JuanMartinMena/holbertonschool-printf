#include "main.h"
int main (void)
{
	int len;
	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	return (len);
}

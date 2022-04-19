#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - a replica of the stlib printf func
 *
 * @format: format specifiers
 * Return: no. of chars printed excluding null
 */
int _printf(const char *format, ...)
{
int char_count;
va_list ap;

if (format == NULL)
	return (-1);

va_start(ap, format);
va_arg(ap, int);
va_end(ap);
return (char_count);
}

/**
 * get_spec - returns a char rep the conversion specifier
 *
 * @s: char array with format '%<char>'
 *
 * Return: char
 */
char get_spec(char *s)
{
switch (*(s + 0))
{
	case 'c':
		return ('c');
	case 's':
		return ('s');
	default:
		return (*(s + 1));
}
}

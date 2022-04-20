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
int i, n, char_count;
va_list ap;
char c, c2;
if (format == NULL)
	return (-1);

char_count = 0;
n = get_args_count(format);
va_start(ap, format);
for (i = 0; i < n; i++)
{
	c = *(format + i);
	c2 = *(format + ++i);
	if (c == '%' && c2 != '\0')
		process_char(c2, ap);
	else
		putchar(c);
	char_count++;
}
va_end(ap);

return (char_count);
}
/**
 * process_char - outputs formatted srings
 *
 * @type: character type specifier
 * @ap: va_list
 * Return: Nothing
 */
void process_char(char type, va_list ap)
{
switch (type)
{
	case 'c':
		printf("%c", va_arg(ap, int));
		break;
	case 's':
		printf("%s", va_arg(ap, char *));
		break;
	case '%':
		printf("%");
		break;
	default:
		printf("%c", type);
		break;
}
}
/**
 * get_args_count - gets the number of format sepcifier
 *
 * @f: format string
 *
 * Return: Number of args
 */
int get_args_count(const char *f)
{
int i, count;

i = 0;
count = 0;
while (*(f + i) != '\0')
{
	if (*(f + i) == '%')
	{
		if (is_correct(*(f + ++i)))
			count++;
	}
	i++;
}

return (count);
}

/**
 * is_correct - checks if char is part of list
 *
 * @c: character with format '%<char>'
 *
 * Return: 0 (false) and 1 (true)
 */
int is_correct(char c)
{
switch (c)
{
	case 'c':
	case 's':
	case '%':
		return (1);
	default:
		return (0);
}
}

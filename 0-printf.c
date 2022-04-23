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
int i, char_count, len, ret;
va_list ap;
char c, c2;
if (format == NULL)
	return (-1);

i = 0;
ret = 0;
char_count = 0;
len = 0;
len = _strlen(format);

va_start(ap, format);

if (*(format + i) == '%' && len == 1)
	return (-1);

while (i < len)
{
	c = *(format + i);
	c2 = *(format + (i + 1));
	if (c == '%' && c2 != '\0')
	{
		ret = process_char(c2, ap);
		i++;
	}
	else
	{
		putchar(c);
		ret = 1;
	}
	char_count += ret;
	i++;
}
va_end(ap);

return (char_count);
}
/**
 * _strlen - gets the length of char array
 *
 * @s: pointer to array of chars
 *
 * Return: Number of chars in s
 */
int _strlen(const char *s)
{
int i, count;

i = 0;
count = 0;

while (*(s + i) != '\0')
{
	count++;
	i++;
}
return (count);
}
/**
 * process_char - outputs formatted srings
 *
 * @type: character type specifier
 * @ap: va_list
 * Return: Nothing
 */
int process_char(char type, va_list ap)
{
int num;

num = 0;
switch (type)
{
	case 'c':
		num = printf("%c", va_arg(ap, int));
		break;
	case 's':
		num = printf("%s", va_arg(ap, char *));
		break;
	case '%':
		num = printf("%%");
		break;
	case 'i':
	case 'd':
		num = printf("%d", va_arg(ap, int));
		break;
	case 'u':
		num = printf("%u", va_arg(ap, unsigned int));
		break;
	case 'o':
		num = printf("%o", va_arg(ap, unsigned int));
		break;
	case 'x':
		num = printf("%x", va_arg(ap, unsigned long));
		break;
	case 'X':
		num = printf("%X", va_arg(ap, unsigned long));
		break;
	case 'p':
		num = printf("%p", va_arg(ap, unsigned long));
		break;
	default:
		num = printf("%%%c", type);
		break;
}

return (num);
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
	case 'u':
	case 'd':
	case 'i':
		return (1);
	default:
		return (0);
}
}

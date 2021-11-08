#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i;
	char *s;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			count += _putchar(*format);
			format++;
			continue;
		}
		format++;
		while (*format == ' ')
		{
			format++;
		}
		switch (*format)
		{
			case 'c':
				count += _putchar(va_arg(args, int));
				format++;
				break;
			case 's':
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					count += _putchar(*s);
					s++;
				}
				format++;
				break;
			case '%':
				count += _putchar(*format);
				format++;
				break;
			case 'd':
			case 'i':
				i = va_arg(args, int);
				if (i < 0)
				{
					i = -i;
					_putchar('-');
				}
				s = convert(i, 10);
				while (*s != '\0')
				{
					count += _putchar(*s);
					s++;
				}
				format++;
				break;
			default:
				while (*format != '%')
				{
					format--;
				}
				count += _putchar(*format);
				format++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * convert - converts number to base
 * @num: number to convert
 * @base: base to convert to
 * Return: pointer to converted number
 */
char *convert(int num, int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = Representation[num%base];
		num /= base;
	}while (num != 0);
	return (ptr);
}

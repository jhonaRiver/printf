#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
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
			format++;
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
			default:
				format--;
				count += _putchar(*format);
				format++;
		}
	}
	va_end(args);
	return (count);
}

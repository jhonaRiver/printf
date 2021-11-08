#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
			format++;
			continue;
		}
		format++;
		switch (*format)
		{
			case 'c':
				_putchar(va_arg(args, int));
				format++;
				count++;
				break;
			case 's':
				while (*format != '\0')
				{
					_putchar(va_arg(args, int));
					format++;
					count++;
				}
				break;
		}
	}
	return (count);
}

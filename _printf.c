#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: character strings
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
				break;
			case 's':
				count += _puts(va_arg(args, char *));
				break;
			case '%':
				count += _putchar(*format);
				break;
			case 'd':
			case 'i':
				count += _putnum(va_arg(args, int));
				break;
			default:
				while (*format != '%')
					format--;
				count += _putchar(*format);
		}
		format++;

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
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}

/**
 * _puts - prints string
 * @s: string to be printed
 * Return: number of characters printed
 */
int _puts(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}

/**
 * _putnum - prints number
 * @num: number to be printed
 * Return: number of characters printed
 */
int _putnum(int num)
{
	int count = 0;
	char *s;

	if (num < 0)
	{
		num = -num;
		count += _putchar('-');
	}
	s = convert(num, 10);
	while (*s != '\0')
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
		return (write(1, &c, 1));
}

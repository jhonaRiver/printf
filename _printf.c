#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	/*unsigned int i;*/
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
			/*case 'd':
				i = va_arg(args, int);
				if (i < 0)
				{
					i = -i;
					count += _putchar('-');
				}
				_puts(convert(i, 10));
				break;
			case 'i':
				break;*/
			default:
				format--;
				count += _putchar(*format);
				format++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * convert - converts number to base
 * @num: number to be converted
 * @base: base to be converted to
 * Return: pointer to the converted number
 */
/*char *convert(unsigned int num, int base)
{
    static char buff[33];
    char *ptr;

    ptr = &buff[sizeof(buff) - 1];
    *ptr = '\0';

    do
    {
        *--ptr = "0123456789abcdef"[num % base];
        num /= base;
    }
    while (num != 0);

    return(ptr);
}*/

/**
 * _puts - print strings
 * @s: string to be printed
 * Return: number of characters printed
 */
/*int _puts(const char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] != NULL)
		{
			_putchar(s[i]);
		}
		i++;
    return (i);
}*/

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
char *convert(int num, int base);
int _puts(char *s);
int _putnum(int num);
#endif

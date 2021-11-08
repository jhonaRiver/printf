#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format_types - struct for identifying format type
 * @identifier: conversion specifier
 * @f: function pointer
 */
typedef struct format_types
{
	char *identifier;
	void (*f)(char *format, va_list args);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);
void print_char(char *format, va_list args);
void print_string(char*format, va_list args);
#endif

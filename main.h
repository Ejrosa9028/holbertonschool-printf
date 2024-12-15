#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
/* Prototipos de las funciones manejadoras */
int handlers_c(va_list args);
int handlers_s(va_list args);
int handlers_di(va_list args);
int handlers_u(va_list args);
int handlers_o(va_list args);
int handlers_x(va_list args);
int handlers_X(va_list args);
int handlers_p(va_list args);
int handlers_percent(va_list args);
int print_unsig(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned long n, int uppercase);
int print_number(int n);

int handle_process(const char *format, va_list args);
int _putchar(char c);
int _printf(const char *format, ...);
#endif

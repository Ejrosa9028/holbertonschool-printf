#include "main.h"

/**
 * handlers_p - handles the %p format specifier (pointer address)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_p(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;

	if (ptr == NULL)
	{
		count += _putchar('0');
		count += _putchar('x');
		count += _putchar('0');
	}
	else
	{
		count += _putchar('0');
		count += _putchar('x');
		count += print_hex((unsigned long)ptr, 0); /*Print pointer as hexadecimal*/
	}
	return (count);
}

/**
 * handlers_c - handles the %c format specifier (character)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_c(va_list args)
{
	char c = va_arg(args, int);  /*'char' se extrae como un 'int' con va_arg*/

	return (_putchar(c));  /*Imprime el carácter*/
}

/**
 * handlers_s - handles the %s format specifier (string)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_s(va_list args)
{
	char *str = va_arg(args, char *);  /*Extrae la cadena*/
	int count = 0;

	if (str == NULL) /*Maneja el caso de una cadena nula*/
	{
		str = "(null)";
	}

	while (*str)
	{
		count += (_putchar(*str));
		str++;
	}

	return (count);
}

/**
 * handlers_di - handles the %d and %i format specifiers (integers)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_di(va_list args)
{
	int n = va_arg(args, int);

	return (print_number(n));  /*Suponiendo que tienes una función print_number*/
}

/**
 * handlers_percent - handles the %% format specifier (percent sign)
 * @args: list of variable arguments passed to _printf (unused)
 *
 * Return: number of characters printed
 */
int handlers_percent(va_list args)
{
	(void)args;  /*No arguments needed*/

	return (_putchar('%'));
}

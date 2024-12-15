#include "main.h"

/**
 * handlers_o - handles the %o format specifier (octal)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_o(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		count += _putchar('0');
	}
	else
	{
		count += print_octal(n);
	}

	return (count);
}

/**
 * print_octal - helper function to print unsigned integers in octal
 * @n: the unsigned integer to print
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
	{
		count += print_octal(n / 8);
	}

	count += _putchar((n % 8) + '0');

	return (count);
}

/**
 * handlers_x - handles the %x format specifier (hexadecimal, lowercase)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_x(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		count += _putchar('0');
	}
	else
	{
		count += print_hex(n, 0);  /*lowercase hex*/
	}
	return (count);
}

/**
 * handlers_X - handles the %X format specifier (hexadecimal, uppercase)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_X(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	if (n == 0)
	{
		count += _putchar('0');
	}
	else
	{
		count += print_hex(n, 1);  /*uppercase hex*/
	}

	return (count);
}

/**
 * print_hex - helper function to print unsigned integers in hexadecimal
 * @n: the unsigned integer to print
 * @uppercase: flag to decide between lowercase and uppercase
 * Return: number of characters printed
 */
int print_hex(unsigned long n, int uppercase)
{
	int count = 0;
	char *hex_chars_lower = "0123456789abcdef";
	char *hex_chars_upper = "0123456789ABCDEF";
	char *hex_chars = uppercase ? hex_chars_upper : hex_chars_lower;

	if (n / 16)
	{
		count += print_hex(n / 16, uppercase);
	}

	count += _putchar(hex_chars[n % 16]);
	return (count);
}

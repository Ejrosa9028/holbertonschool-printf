#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 * Return: the number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)  /*Si el número es negativo*/
	{
		count += _putchar('-');  /*/Imprimir el signo negativo*/
		n = -n;  /*Hacer el número positivo para manejar la impresión*/
	}

	if (n / 10)  /*Si el número tiene más de un dígito*/
	{
		count += print_number(n / 10);  /*Llamada recursiva  dígitos anteriores*/
	}

	count += _putchar((n % 10) + '0');  /*Imprimir el dígito actual*/
	return (count);
}

/**
 * handlers_u - handles the %u format specifier (unsigned)
 * @args: list of variable arguments passed to _printf
 *
 * Return: number of characters printed
 */
int handlers_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	int count = 0;

	if (n == 0)
	{
		count += _putchar('0');
	}
	else
	{
		count += print_unsig(n);
	}

	return (count);
}

/**
 * print_unsig - helper function to print unsigned integers
 * @n: the unsigned integer to print
 * Return: number of characters printed
 */
int print_unsig(unsigned int n)
{
	int count = 0;

	if (n / 10)
	{
		count += print_unsig(n / 10);
	}

	count += _putchar((n % 10) + '0');
	return (count);
}

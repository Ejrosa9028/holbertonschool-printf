#include "main.h"

/**
 * _printf - Processes a single format specifier
 *
 * @format: format specifier to handle
 * @...: list of arguments for the specifier
 *
 * Return: number of characters printed for the specifier
 */
int _printf(const char *format, ...)
{
	va_list args; /*Declara lista de argumentos*/
	int count = 0; /*Cuenta el numero de caracteres*/
	int i;

	if (!format) /*Si format es NULL, devuelve -1 como error */
	{
		return (-1);
	}

	va_start(args, format); /*Inicializar lista de argumento*/

	for (i = 0; format[i] != '\0'; i++) /*Recorre string de caracter a caracter*/
	{
		if (format[i] == '%') /*Si es '%' indica un especificador de formato*/
		{
			i++; /*Avanza al siguiente caracter*/

			count += handle_process(&format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
	}

	va_end(args);
	return (count);
}

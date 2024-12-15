#include "main.h"
/**
 * handle_process - Processes a single format specifier
 *
 * @format: format specifier to handle
 * @args: list of arguments for the specifier
 *
 * Return: number of characters printed for the specifier
 */
int handle_process(const char *format, va_list args)
{
	int count = 0;

	if (!format)
		return (-1);

	switch (*format)
	{
		case 'c':
			count += handlers_c(args);  /*Handle character*/
			break;
		case 's':
			count += handlers_s(args);  /*Handle string*/
			break;
		case 'd':
		case 'i':
			count += handlers_di(args);  /*Handle integers*/
			break;
		case 'u':
			count += handlers_u(args);  /*Handle unsigned integers*/
			break;
		case 'o':
			count += handlers_o(args);  /*Handle octal*/
			break;
		case 'x':
			count += handlers_x(args);  /*Handle hexadecimal (lowercase)*/
			break;
		case 'X':
			count += handlers_X(args);  /*Handle hexadecimal (uppercase)*/
			break;
		case 'p':
			count += handlers_p(args);  /*Handle pointer address*/
			break;
		case '%':
			count += handlers_percent(args);  /*Handle percent sign*/
			break;
		default:
			count += _putchar('%');  /*Handle unknown specifiers*/
			count += _putchar(*format);
			break;
	} return (count);
}

#include "shell.h"
/**
 * myprinter - prints a character
 * @format: the format to be printed
 * @...: variable functions
 * Return: 1 on success
 */


int  myprinter(const char *format, ...)
{
	unsigned int index = 0, total_value = 0;
	va_list args;
	int total_val;

	va_start(args, format);

	for ( ; format[index] != '\0'; index++)
	{

		if (format[index] != '%')
		{
			we_putchar(format[index]);
		}

		else if (format[index + 1] == 'c')
		{
			we_putchar(va_arg(args, int));
			index++;
		}
		else if (format[index + 1] == 's')
		{
			total_val =  we_putstring(va_arg(args, char *));
			index++;
			total_value += (total_val - 1);
		}
		else if (format[index + 1] == '%')
		{
			we_putchar('%');
			index++;
		}
		else if ((format[index + 1] == 'd') || (format[index + 1] == 'i'))
		{
			we_int(va_arg(args, int));
			index++;
		}

			total_value += 1;

		}
	return (total_value);

}

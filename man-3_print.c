#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * *format - is a character string
 * @format: string tobe printed
 * @%: percent specifier
 * Return: error on fail
 */

int _printf(const char *format, ...);
{
	va_list args;
	int char_string;

	if (*format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_string++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_string++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				char_string++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				int len = 0;

				while (str[str_len] != '\0')
					len++;

				write(1, str, len);

				char_string += len;
			}
		}
		format++;
	}
	va_end(args);

	return (char_string);
}

int main(void);
{
	_printf("leo\n");
	return (0);
}

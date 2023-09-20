#include "main.h"

/**
 * _printf - Prints formatted text to the standard output.
 * @format: A format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int num_of_char = 0;

	va_list args_list;

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			num_of_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case 's':
				{
					char *str = va_arg(args_list, char *);
					int str_len = 0;

					while (str[str_len] != '\0')
					{
						_putchar(str[str_len]);
						num_of_char++;
						str_len++;
					}
					break;
				}
				case 'c':
				{
					char c = va_arg(args_list, int);
					_putchar(c);
					num_of_char++;
					break;
				}
				case '%':
				{
					_putchar('%');
					num_of_char++;
					break;
				}
				default:
				{
					_putchar('%');
					num_of_char++;
					_putchar(*format);
					num_of_char++;
				}
			}
		}

		format++;
	}

	va_end(args_list);

	return (num_of_char);
}

#include "monty.h"

/**
 * _putchar - print char
 * @fd: file discriptor
 * @c: the char u wanna print
 * Return: Always 1
 */
int	_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

/**
 * _putnbr - print number
 * @fd: file discriptor
 * @nb: the number u wanna print
 * Return: length of number
 */
int	_putnbr(int fd, int nb)
{
	long	nb1;
	int			l;

	nb1 = (long)nb;
	l = 0;
	if (nb1 < 0)
	{
		l = _putchar(fd, '-');
		nb1 *= -1;
	}
	if (nb1 > 9)
	{
		l += _putnbr(fd, nb1 / 10);
		_putnbr(fd, nb1 % 10);
	}
	else
		_putchar(fd, nb1 + '0');
	return (l + 1);
}

/**
 * _putstr - print string
 * @fd: file discriptor
 * @s: string
 * Return: length of string
 */
int	_putstr(int fd, char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * checks - check for the exact specifier
 * @fd: file discriptor
 * @argp: the va_list
 * @str: the string format
 * @loc: the struct of vars
 * Return: length
 */
static int	checks(int fd, va_list	argp, const char *str, t_locals *loc)
{
	int	len;

	len = 0;
	if (str[loc->i] == 's')
		len = _putstr(fd, va_arg(argp, char *));
	else if (str[loc->i] == '%')
		len = _putchar(fd, '%');
	else if (str[loc->i] == 'd' || str[loc->i] == 'i')
		len = _putnbr(fd, va_arg(argp, int));
	else
	{
		len = _putchar(fd, '%');
		len += _putchar(fd, str[loc->i]);
	}
	loc->i++;
	return (len);
}

/**
 * _printf - produces out_put according to a format.
 * @fd: file discriptor
 * @format: character string
 * Return: length of the out_put
 */
int _print_fd(int fd, const char *format, ...)
{
	va_list		argp;
	t_locals	loc;

	va_start(argp, format);

	loc.i = 0;
	loc.glen = 0;
	if (!format)
		return (-1);

	while (format[loc.i])
	{
		if (format[loc.i] == '%')
		{
			loc.i++;
			if (!format[loc.i])
			{
				va_end(argp);
				return (-1);
			}
			loc.glen += checks(fd, argp, format, &loc);
		}
		else
		{
			write(fd, &format[loc.i], 1);
			loc.i++;
			loc.glen++;
		}
	}
	va_end(argp);
	return (loc.glen);
}


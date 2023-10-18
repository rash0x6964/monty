#include "monty.h"

/**
 * args_counter - count the words separated by the given charsets
 * @str: string
 * @charsets: string of separators
 * Return: the number of words exist
 */
int	args_counter(char *str, char *charsets)
{
	int	i = 0;
	int	count = 0;

	while (str[i])
	{
		while (str[i] && strchr(charsets, str[i]))
			i++;
		if (str[i])
		{
			count++;
			i++;
		}
		while (str[i] && !strchr(charsets, str[i]))
			i++;
	}
	return (count);
}

/**
 * _split - split the string to seperates word
 * @s: stack
 * @str: the given string
 * @delim: seperators
 * Return: array of strings
 */
char **_split(stack_tt *s, char *str, char *delim)
{
	char **args;
	size_t i = 0;
	size_t len = args_counter(str, delim);
	char *res = strtok(str, delim);

	args = malloc(sizeof(char *) * (len + 1));
	if (!args)
	{
		_print_fd(2, "Error: malloc failed\n");
		free_dlistint(s);
		close(fd);
		exit(EXIT_FAILURE);
	}

	while (i < len)
	{
		args[i] = strdup(res);
		if (!args[i++])
		{
			_print_fd(2, "Error: malloc failed\n");
			free_dlistint(s);
			close(fd);
			exit(EXIT_FAILURE);
		}
		res = strtok(NULL, delim);
	}
	args[i] = NULL;

	return (args);
}

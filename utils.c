#include "monty.h"

/**
 * _puts_error - Prints a string in stderror.
 * @str: string to be printed.
 * Return: Nothing
 */
void _puts_error(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(2, &str[i], 1);
}

/**
 * validate_file_instructions - print an error
 * @s: stack
 * @lineNb: line number in file
 * @opCode: invalid instrucion
 * Return: nothing
 */
void validate_file_instructions(stack_tt *s, int lineNb, char *opCode)
{
	_print_fd(2, "L%d: unknown instruction %s\n", lineNb, opCode);
	free_dlistint(s);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * _is_number - check it's a number
 * @str: string
 * Return: 0 or 1
 */
int _is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

/**
 * get_number - get a number form array
 * @s: stack
 * @array: array
 * @counter: counter of line
 * Return: int
 */
int get_number(stack_tt *s, char **array, int counter)
{
	int i = 1;

	if (!array[i] || !_is_number(array[i]))
	{
		_print_fd(2, "L%d: usage: push integer\n", counter);
		free_dlistint(s);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	return (atoi(array[i]));
}

/**
 * free_array - free the two dimensional array
 * @array: two dimensional array
 * Return: Nothing
 */
void free_array(char **array)
{
	size_t i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

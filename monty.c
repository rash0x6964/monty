#include "monty.h"

/**
 * preper_inputFile - check access/open the file
 * @argc: number of args
 * @argv: array of args
 * Return: fd to file
*/
FILE *preper_inputFile(int argc, char **argv)
{
	char *file;

	if (argc != 2)
	{
		_print_fd(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = argv[1];
	if (access(file, F_OK | R_OK) != 0)
	{
		_print_fd(2, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	fd = fopen(file, "r");
	return (fd);
}

/**
 * fetch_line - get a splited line
 * @s: stack
 * Return: array
*/
char **fetch_line(stack_tt *s)
{
	ssize_t len = 0;
	size_t bufsize = 0;
	char *buffer = NULL;

	len = getline(&buffer, &bufsize, fd);
	if (len == -1)
	{
		free_dlistint(s);
		close(fd);
		exit(EXIT_SUCCESS);
	}

	return (_split(s, buffer, " \t\n"));
}

/**
 * operations - implement the op at the stack
 * @s: stack
 * @counter: line number
 * Return: nothing
*/
void operations(stack_tt **s, int counter)
{
	int number;
	char **array = fetch_line(*s);

	if (!array[0])
	{
		free_array(array);
		return;
	}

	if (strcmp(array[0], "push") == 0)
	{
		number = get_number(*s, array, counter);
		puch_to_stack(s, number);
	}
	else if (strcmp(array[0], "pall") == 0)
		print_stack(*s);
	else
		validate_file_instructions(counter, array[0]);

	free_array(array);
}

/**
 * main - entery point
 * @argc: arg count
 * @argv: array of args
 * Return: int
*/
int main(int argc, char **argv)
{
	stack_tt *s;
	int counter = 0;
	FILE *fd = preper_inputFile(argc, argv);

	while (1)
	{
		counter++;
		operations(&s, counter);
	}
}

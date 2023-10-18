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
	FILE *file_fd;

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

	file_fd = fopen(file, "r");
	return (file_fd);
}

/**
 * fetch_line - get a splited line
 * @file_fd: fd of file
 * @s: stack
 * Return: array
*/
char **fetch_line(FILE *file_fd, stack_tt *s)
{
	ssize_t len = 0;
	size_t bufsize = 0;
	char *buffer = NULL;

	len = getline(&buffer, &bufsize, file_fd);
	if (len == -1)
	{
		free_dlistint(s);
		exit(EXIT_SUCCESS);
	}

	return (_split(buffer, " \n"));
}

/**
 * operations - implement the op at the stack
 * @file_fd: file fd
 * @s: stack
 * @counter: line number
 * Return: nothing
*/
void operations(FILE *file_fd, stack_tt **s, int counter)
{
	char **array = fetch_line(file_fd, *s);

	if (strcmp(array[0], "push") == 0)
	{
		int number = get_number(*s, array, counter);
		puch_to_stack(s, number);
	}
	else if (strcmp(array[0], "pall") == 0)
		print_stack(*s);

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
	FILE *file_fd = preper_inputFile(argc, argv);

	while (1)
	{
		counter++;
		operations(file_fd, &s, counter);
	}
}

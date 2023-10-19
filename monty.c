#include "monty.h"

t_global_var g = {NULL, 0};

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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = argv[1];
	if (access(file, F_OK | R_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	g.fd = fopen(file, "r");
	return (g.fd);
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

	len = getline(&buffer, &bufsize, g.fd);
	if (len == -1)
	{
		free(buffer);
		free_dlistint(s);
		fclose(g.fd);
		exit(EXIT_SUCCESS);
	}

	return (_split(s, buffer, " \t\n"));
}

/**
 * operations - implement the op at the stack
 * @s: stack
 * Return: nothing
 */
void operations(stack_tt **s)
{
	int i = 0;
	char **array = fetch_line(*s);

	instruction_t opst[] = {
			{"push", push}, {"pall", pall}, {"pint", pint},
			{"pop", pop}, {"swap", swap}, {"add", add},
			{"nop", nop}, {"sub", sub}, {NULL, NULL}
	};

	if (!array[0])
	{
		free_array(array);
		return;
	}

	while (opst[i].opcode)
	{
		if (strcmp(array[0], opst[i].opcode) == 0)
		{
			opst[i].f(s, array);
			break;
		}
		i++;
	}

	if (opst[i].opcode == NULL)
		validate_file_instructions(*s, array);

	free_array(array);
}

/**
 * f - detect leaks
 * Return: nothing
 */
void f(void) { system("leaks monty"); }

/**
 * main - entery point
 * @argc: arg count
 * @argv: array of args
 * Return: int
 */
int main(int argc, char **argv)
{
	stack_tt *s = NULL;

	g.fd = preper_inputFile(argc, argv);

	while (1)
	{
		(g.counter)++;
		operations(&s);
	}
}

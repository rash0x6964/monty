#include "monty.h"

/**
 * push - push to stack
 * @s: stack
 * @array: splited line
 * Return: nothing
 */
void push(stack_tt **s, char **array)
{
	int number = get_number(*s, array);

	add_dnodeint(s, number, array);
}

/**
 * pall - print the stack
 * @s: stack
 * @array: unused param
 * Return: nothing
 */
void pall(stack_tt **s, char **array)
{
	(void)array;
	print_dlistint(*s);
}

/**
 * pint - prints the top
 * @s: stack head
 * @array: splited line
 * Return: nothing
 */
void pint(stack_tt **s, char **array)
{
	if (!*s)
	{
		fprintf(stderr, "L%lu: can't pint, stack empty\n", counter);
		fclose(fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
	fflush(stdout);
}

/**
 * pop - prints the top and remove it
 * @s: stack s
 * @array: splited line
 * Return: no return
 */
void pop(stack_tt **s, char **array)
{
	stack_tt *tmp;

	if (*s == NULL)
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", counter);
		fclose(fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}
	tmp = *s;
	*s = tmp->next;
	free(tmp);
}

/**
 * add - add the top two elements of the stack
 * @s: Double pointer to the stack
 * @array: splited line
 * Return: void
 */
void add(stack_tt **s, char **array)
{
	stack_tt *temp = *s;

	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%lu: can't add, stack too short\n", counter);
		fclose(fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n += (*s)->n;
	*s = (*s)->next;
	(*s)->prev = NULL;

	free(temp);
}

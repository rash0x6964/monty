#include "monty.h"

/**
 * nop - Does nothing.
 * @s: double pointer to the stack
 * @array: unused
 */
void nop(stack_tt **s, char **array)
{
	(void)s;
	(void)array;
}

/**
 * swap - swaps the top two elements of the stack
 * @s: double pointer to the stack
 * @array: splited line
 * Return: void
 */
void swap(stack_tt **s, char **array)
{
	int holder;
	stack_tt *current = *s;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", g.counter);
		fclose(g.fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}

	holder = current->next->n;
	current->next->n = current->n;
	current->n = holder;
}

/**
 * sub - Subtract the top element of the stack from the second top element
 * @s: Double pointer to the stack
 * @array: splited line
 * Return: nothing
 */
void sub(stack_tt **s, char **array)
{
	stack_tt *temp;
	int result;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", g.counter);
		fclose(g.fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}

	result = (*s)->next->n - (*s)->n;
	temp = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	free(temp);

	(*s)->n = result;
}

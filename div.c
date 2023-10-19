#include "monty.h"

/**
 * _div  - Divide the second top element of the stack by the top element
 * @s: Double pointer to the stack.
 * @array: splited line
 * Return: nothing
 */
void _div(stack_tt **s, char **array)
{
	stack_tt *temp;

	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", g.counter);
		fclose(g.fd);
		free_array(array);
		free_dlistint(*s);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n /= (*s)->n;
	temp = *s;
	*s = (*s)->next;
	free(temp);
}


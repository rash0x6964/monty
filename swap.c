#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: unused
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int holder;
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap\n", line_number);
		exit(EXIT_FAILURE);
	}

	holder = current->next->n;
	current->next->n = current->n;
	current->n = holder;
}


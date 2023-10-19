#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: unused
 *
 * Return: void
 */
void add(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}


#include "monty.h"

/**
 * div  - Divide the second top element of the stack by the top element
 * @stack: Double pointer to the stack.
 * @line_number: Unused argument.
 */
void div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by 0\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}


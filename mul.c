#include "monty.h"

/**
 * mul - Multiply the second top element of the stack with the top element
 * @stack: Double pointer to the stack
 * @line_number: Unused argument.
 * Return: nothing
 */
void mul(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp;
	(void)line_number;

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}


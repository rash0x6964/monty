#include "monty.h"

/**
 * pall - print all elements of the stack
 * @stack: double pointer to the stack
 * @line_number: unused
 *
 * Return: void
 */
void pall(stack_tt **stack, unsigned int line_number)
{
	stack_tt *current_node = *stack;

	(void)line_number;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}


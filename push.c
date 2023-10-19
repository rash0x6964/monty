#include "monty.h"

/**
 * push - push a new node to the stack
 * @stack: double pointer to the stack
 * @value: value to be added to the stack
 */
void push(stack_tt **stack, unsigned int value)
{
	stack_tt *new_node = malloc(sizeof(stack_tt));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}


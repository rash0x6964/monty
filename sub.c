#include "monty.h"

/**
 * sub - Subtract the top element of the stack from the second top element
 * @head: Double pointer to the stack
 */
void sub(stack_tt **head)
{
	stack_tt *temp;
	int result;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", g.counter);
		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n - (*head)->n;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);

	(*head)->n = result;
}

#include "monty.h"

/**
 * add_dnodeint -  function that adds a new node at the beginning of a list
 * @head: the head of the list
 * @n: new node value
 * @array: splited line
 * Return: address of the new element or NULL
 */

stack_tt *add_dnodeint(stack_tt **head, const int n, char **array)
{
	stack_tt *new_node;

	new_node = malloc(sizeof(stack_tt));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(g.fd);
		free_dlistint(*head);
		free_array(array);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}

/**
 * print_dlistint - function that prints all the elements
 * @h: the first node
 * Return: the number of nodes
*/
size_t print_dlistint(const stack_tt *h)
{
	size_t index = 0;

	while (h)
	{
		printf("%d\n", h->n);
		fflush(stdout);
		index++;
		h = h->next;
	}
	return (index);
}

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: first node
 * Return: Nothing
 */
void free_dlistint(stack_tt *head)
{
	stack_tt *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

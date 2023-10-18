#include "monty.h"

void puch_to_stack(stack_tt **s, int number)
{
	add_dnodeint(s, number);
}

void print_stack(stack_tt *s)
{
	print_dlistint(s);
}

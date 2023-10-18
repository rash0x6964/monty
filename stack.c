#include "monty.h"

/**
 * puch_to_stack - puch to stack
 * @s: stack
 * @number: value of new node
 * Return: nothing
*/
void puch_to_stack(stack_tt **s, int number)
{
	add_dnodeint(s, number);
}

/**
 * print_stack - print the stack
 * @s: stack
 * Return: nothing
*/
void print_stack(stack_tt *s)
{
	print_dlistint(s);
}
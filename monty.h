#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <string.h>
#include <ctype.h>

extern FILE *fd;
extern size_t counter;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_tt;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_tt **s, char **array);
} instruction_t;

/* utils */
void _puts_error(char *str);
void validate_file_instructions(stack_tt *s, char **array);
int _is_number(char *str);
int get_number(stack_tt *s, char **array);
void free_array(char **array);

/* tokenizer */
char **_split(stack_tt *s, char *str, char *delim);

/* lists */
stack_tt *add_dnodeint(stack_tt **head, const int n, char **array);
size_t print_dlistint(const stack_tt *h);
void free_dlistint(stack_tt *head);

/* stack */
void push(stack_tt **s, char **array);
void pall(stack_tt **s, char **array);
void pint(stack_tt **s, char **array);
void pop(stack_tt **s, char **array);
void swap(stack_tt **s, char **array);
void add(stack_tt **s, char **array);
void nop(stack_tt **s, char **array);

#endif

#ifndef MONTY_H
# define MONTY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

#include <string.h>
#include <ctype.h>

extern fd;

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
	void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;


/* utils */
void _puts_error(char *str);
void validate_file_instructions(stack_t *s, int lineNb, char *opCode);
int _is_number(char *str);
int get_number(stack_tt *s, char **array, int counter);
void free_array(char **array);

/* tokenizer */
char **_split(stack_tt *s, char *str, char *delim);

/* lists */
stack_tt *add_dnodeint(stack_tt **head, const int n);
size_t print_dlistint(const stack_tt *h);
void free_dlistint(stack_tt *head);

/* stack */
void puch_to_stack(stack_tt **s, int number);
void print_stack(stack_tt *s);

/*++++++++++++++++++++++++++ PRINT FD ++++++++++++++++++++++++++++++++++*/

# include<stdarg.h>

/**
 *struct s_locals - New data type as t_locals
 *@i: index of while
 *@glen: length of string i printed
 */
typedef struct s_locals
{
	int i;
	int glen;
} t_locals;

int _print_fd(int fd, const char *format, ...);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#endif

#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>

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
} stack_t;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pall(stack_t **t, unsigned int line_number);
void free_dlist(stack_t **head);
int add_end_dnode(stack_t **head, int n);
void push(stack_t **t, unsigned int line_number);
int is_number(const char *input);
void opening_error(char **argv);
void instruction_error(char *instruction, unsigned int line_number);
void not_int_err(unsigned int line);
void malloc_error(void);
void open_read(char **argv);
int is_comment(char *token, int line_number);
void free_stack(stack_t *top);
void (*get_op(char *tok, unsigned int line_number))(stack_t **stack, unsigned int);
ssize_t _getline(char** lineptr, size_t* n, FILE* stream);




#endif

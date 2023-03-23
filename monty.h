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
/**
 * struct bus_s - variables arguments, file and line content
 * @arg: value
 * @fp: pointer to a monty file
 * @file_content: the line content
 * @lifi: flag change stack <-> queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *fp;
	char *file_content;
	int lifi;
} bus_t;
extern bus_t bus;

ssize_t getline(char **lineptr, size_t *size, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void push(stack_t **top, unsigned int count);
void pall(stack_t **top, unsigned int count);
void free_stack(stack_t *top);
void addnode(stack_t **top, int n);
void addqueue(stack_t **top, int n);
int execute(char *file_content, stack_t **stack, unsigned int count, FILE *fp);
void pint(stack_t **top, unsigned int count);
void pop(stack_t **top, unsigned int count);
void swap(stack_t **top, unsigned int count);
void add(stack_t **top, unsigned int count);
void nop(stack_t **top, unsigned int count);
void sub(stack_t **top, unsigned int count);
void div1(stack_t **top, unsigned int count);
void mul(stack_t **top, unsigned int count);
void mod(stack_t **top, unsigned int count);
void pchar(stack_t **top, unsigned int count);
void pstr(stack_t **top, unsigned int count);
void rotate(stack_t **top, unsigned int count);
void rotr(stack_t **top, unsigned int count);



#endif

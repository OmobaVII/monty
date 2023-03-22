#include "monty.h"

/**
 * pall - a function that prints all nodes in a stack
 * @t: the head of the list
 * @line_number: the bytecode line number
 */

void pall(stack_t **t, unsigned int line_number)
{
	stack_t *temp;

	temp = NULL;

	if (t == NULL || *t == NULL)
	{
		return;
	}
	(void)line_number;
	temp = *t;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * is_number - a function that checks if an input is a number
 * @n: the input
 * Return: 0 if a number and -1 if not
 */
int is_number(const char *input)
{
	int i, negative;

	i = 0;
	negative = 0;

	if (input[i] == '-')
	{
		negative = 1;
		i++;
	}
	for (; input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
			return (-1);
	}
	return (negative ? 0 : 1);
}
/**
 * push - a function that adds a node to the start of a dlinkedlist
 * @t: the head of the linked list
 * @line_number: bytecode line number
 * @n: integer
 */

void push(stack_t **t, unsigned int line_number, const char *n)
{
	if (t == NULL)
		return;
	if (is_number(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dlist(t);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_dnode(t, atoi(n)) == -1)
		{
			free_dlist(t);
			exit(EXIT_FAILURE);
		}
	}
}

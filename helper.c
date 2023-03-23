#include "monty.h"

/**
 * free_stack - function that frees a stack
 * @top: the top of the stack
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *ptr;

	ptr = top;
	while (top != NULL)
	{
		ptr = top->next;
		free(top);
		top = ptr;
	}
}
/**
 * addnode - a function that adds a new node to the top of stack
 * @top: the top of the stack
 * @n: the new value
 * Return: void
 */
void addnode(stack_t **top, int n)
{
	stack_t *new, *ptr;

	ptr = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ptr)
		ptr->prev = new;
	new->n = n;
	new->next = *top;
	new->prev = NULL;
	*top = new;
}
/**
 * addqueue - a function that adds a node to the tails of the stack
 * @n: the value of the new node
 * @top: the top of the stack
 * Return: void
 */
void addqueue(stack_t **top, int n)
{
	stack_t *new, *ptr;

	ptr = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (ptr)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
	}
	if (!ptr)
	{
		*top = new;
		new->prev = NULL;
	}
	else
	{
		ptr->next = new;
		new->prev = ptr;
	}
}

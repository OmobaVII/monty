#include "monty.h"

/**
 * add_end_dnode - a function that adds a node at the front of linked list
 * @head: the doubly linked list
 * @n: the data to add
 * Return: 0 for success
 */

int add_end_dnode(stack_t **head, int n)
{
	stack_t *new;

	if (head == NULL)
		return (-1);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	new->n = n;
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (0);
}
/**
 * free_stack - a function that frees a stack
 * @top: a pointer to the top of the stack
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *ptr;

	if (top != NULL)
	{
		ptr = top;
		top = top->next;
		free(ptr);
	}
	free(top);
}
/**
 * free_dlist - a function that frees a double linked list
 * @head: the double linked list
 * Return: void
 */
void free_dlist(stack_t **head)
{
	if (head == NULL)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}

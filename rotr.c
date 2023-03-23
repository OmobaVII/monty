#include "monty.h"

/**
 * rotr - a function that rotates the stack to the bottom
 * @top: the top of the stack
 * @count: unused function
 * Return: void
 */

void rotr(stack_t **top, unsigned int count)
{
	stack_t *ptr;
	(void) count;

	ptr = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *top;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*top)->prev = ptr;
	*top = ptr;
}

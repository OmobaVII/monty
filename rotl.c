#include "monty.h"

/**
 * rotate - a function that rotates the stack to the top
 * @top: the top of the stack
 * @count: the ;ine number
 * Return: void
 */
void rotate(stack_t **top, unsigned int count)
{
	stack_t *ptr, *tmp;
	(void) count;

	ptr = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	tmp = (*top)->next;
	tmp->prev = NULL;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *top;
	(*top)->next = NULL;
	(*top)->prev = ptr;
	*top = tmp;
}

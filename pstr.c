#include "monty.h"

/**
 * pstr- a function that prints the string starting at the top of the stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void pstr(stack_t **top, unsigned int count)
{
	stack_t *ptr;
	(void) count;

	ptr = *top;

	while (ptr != NULL)
	{
		if (ptr->n > 127 || ptr->n <= 0)
		{
			break;
		}
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

#include "monty.h"

/**
 * pop - a function that removes the top of a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void pop(stack_t **top, unsigned int count)
{
	stack_t *ptr;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	*top = ptr->next;
	free(ptr);
}

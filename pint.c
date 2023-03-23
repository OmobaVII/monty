#include "monty.h"

/**
 * pint - a function that prints the top of a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */

void pint(stack_t **top, unsigned int count)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", count);
		fclose(bus.file);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

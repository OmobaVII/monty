#include "monty.h"

/**
 * pchar - a function that prints the char at the top
 * of a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void pchar(stack_t **top, unsigned int count)
{
	stack_t *ptr;

	ptr = *top;
	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptr->n);
}

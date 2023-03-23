#include "monty.h"

/**
 * swap - a function that two top elements in a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void swap(stack_t **top, unsigned int count)
{
	stack_t *ptr;
	int lenght = 0, tmp;

	ptr = *top;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		lenght++;
	}
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	tmp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = tmp;
}

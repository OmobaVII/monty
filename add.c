#include "monty.h"

/**
 * add - a function that adds the top two element of a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void add(stack_t **top, unsigned int count)
{
	stack_t *ptr;
	int lenght = 0;
	int tmp;

	ptr = *top;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		lenght++;
	}
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	tmp = ptr->n + ptr->next->n;
	ptr->next->n = tmp;
	*top = ptr->next;
	free(ptr);
}

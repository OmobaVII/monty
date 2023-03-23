#include "monty.h"

/**
 * mod - a function that takes the remainder of a division of the second
 * element by the first element of a stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void mod(stack_t **top, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.fp);
		free(bus.file_content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	tmp = ptr->next->n % ptr->n;
	ptr->next->n = tmp;
	*top = ptr->next;
	free(ptr);
}

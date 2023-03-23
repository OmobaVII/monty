#include "monty.h"

/**
 * div - a function that divides the second top element of the stack
 * by the top element of the stack
 * @top: the top of the stack
 * @count: the line number
 * Return: void
 */
void div1(stack_t **top, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
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
	tmp = ptr->next->n / ptr->n;
	ptr->next->n = tmp;
	*top = ptr->next;
	free(ptr);
}

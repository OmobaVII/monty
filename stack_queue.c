#include "monty.h"

/**
 * stack1 - a function that sets the format of the data to a stack
 * @top: unused
 * @count: unused
 * Return: void
 */
void stack1(stack_t **top, unsigned int count)
{
	(void)top;
	(void)count;
	bus.lifi = 0;
}
/**
 * queue1 - a function that sets the format of the data to a queue
 * @top: unused
 * @count: unused
 * Return: void
 */
void queue1(stack_t **top, unsigned int count)
{
	(void)top;
	(void)count;
	bus.lifi = 1;
}

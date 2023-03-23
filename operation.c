#include "monty.h"
/**
 * execute - a function that perfroms the opcode
 * @stack: the top of the stack
 * @count: the line counter
 * @fp: pointer to a monty file
 * @file_content: line content
 * Return: 1 on success
 */
int execute(char *file_content, stack_t **stack, unsigned int count, FILE *fp)
{
	instruction_t operation[] = {
				{"pall", pall},
				{"push", push},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", div1},
				{"mul", mul},
				{"mod", mod},
				{NULL, NULL}
	};
	unsigned int a = 0;
	char *op;

	op = strtok(file_content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (operation[a].opcode && op)
	{
		if (strcmp(op, operation[a].opcode) == 0)
		{
			operation[a].f(stack, count);
			return (0);
		}
		a++;
	}
	if (op && operation[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(fp);
		free(file_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}


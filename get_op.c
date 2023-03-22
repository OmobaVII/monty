#include "monty.h"


/**
 * get_op - a function that selects the right operation function
 * @tok: first bytecode
 * Return: void
 */

void (*get_op(char *tok, unsigned int line_number))(stack_t **stack, unsigned int)
{
	instruction_t opcode[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}
	};
	int a = 0;

	while (opcode[a].opcode != NULL)
	{

		if (strcmp(tok, opcode[a].opcode) == 0)
		{
			return (opcode[a].f);
		}
		a++;
	}
	instruction_error(tok, line_number);
	return (NULL);
	
}


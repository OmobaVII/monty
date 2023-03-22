#include "monty.h"


/**
 * get_op - a function that selects the right operation function
 * @tok: first bytecode
 * Return: void
 */

void (*get_op(char *tok))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int a;
	char *instr;

	a = 0;
	while (instruction_s[a].f != NULL)
	{
		instr = strtok(tok, "$");

		if (strcmp(instr, instruction_s[a].opcode) == 0)
		{
			return (instruction_s[a].f);
		}
		a++;
	}
	return (NULL);
}

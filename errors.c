#include "monty.h"
/**
 * opening_error - a function that prints error message if
 * unable to open a file
 * @argv: the file unable to open
 * Return: void
 */
void opening_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * instruction_error - a function that prints a message if file
 * has an invalid instruction
 * @instruction: the instruction
 * @line_number: the number of the line that has in instruction
 * Return: void
 */
void instruction_error(char *instruction, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
/**
 * integer_error - a function that prints a message if the parameter recieved
 * is not an integer
 * @line_number: the number of the line that has the parameter not an integer
 * Return: void
 */
void not_int_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * error_malloc - a function that prints a message if unable to malloc
 * Return: void
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

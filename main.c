#include "monty.h"

#define BUFFER_SIZE 10000
/**
 * main - the entry to the program
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	char *buffer;
	stack_t *stack;
	int fd, n_read, line_number;

	if (argc != 2)
		error_exit("USAGE: monty file\n");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n_read = read(fd, buffer, 10000);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	line_number = 1;
	parse_commands(buffer, &stack, &line_number);

	free_stack(stack);
	free(buffer);
	return (0);
}
/**
 * parse_commands - a function that performs the command
 * @buffer: the command read
 * @stack: the command
 * @line_number: the line in which the command is located
 * Return: void
 */
void parse_commands(char *buffer, stack_t **stack, int *line_number)
{
	char *token;
	int is_push = 0;

	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (is_push)
		{
			push(stack, *line_number, token);
			is_push = 0;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_push = 1;
		}
		else
		{
			execute_command(token, stack, *line_number);
		}
		token = strtok(NULL, "\n\t\a\r ;:");
		(*line_number)++;
	}
}
/**
 * execute_command - a function that executes the command
 * @command: the command to execute
 * @stack: the stack list
 * @line_number: the number of the line we find the command
 * Return: void
 */
void execute_command(char *command, stack_t **stack, int line_number)
{
	void (*op_func)(stack_t **, unsigned int);

	op_func = get_op(command);
	if (op_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
		exit(EXIT_FAILURE);
	}
	op_func(stack, line_number);
}
/**
 * free_stack - a function that frees the stack
 * @stack: the stack to free
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *node;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

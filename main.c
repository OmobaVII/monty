#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - the entry point into the monty interpreter
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *file_content;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	bus.fp = fp;
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		file_content = NULL;
		read = getline(&file_content, &size, fp);
		bus.file_content = file_content;
		count++;
		if (read > 0)
		{
			execute(file_content, &stack, count, fp);
		}
		free(file_content);
	}
	free_stack(stack);
	fclose(fp);
	return (0);
}

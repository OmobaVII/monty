#include "monty.h"

/**
 * main - entry into the program
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	int fd, i_push = 0;
	ssize_t n_read;
	unsigned int line = 1;
	char *buffer, *token;
	stack_t *t = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (buffer == NULL)
		return (0);
	n_read = read(fd, buffer, 10000);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (i_push == 1)
		{
			push(&t, line, token);
			i_push = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			i_push = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op(token) != 0)
			{
				get_op(token)(&t, line);
			}
			else
			{
				free_dlist(&t);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&t);	free(buffer);
	close(fd);
	return (0);
}

#include "monty.h"

int number;
/**
 * open_read - a function that opens, read and execute a file
 * @argv: arguments received from the file
 * Return: void
 */
void open_read(char **argv)
{
	void (*func)(stack_t **, unsigned int);
	FILE *fp;
	char *buf = NULL;
       	char *token = NULL;
	char command[1024];
	size_t len = 0;
	ssize_t line_size;
	unsigned int line_counter = 1;
	stack_t *top = NULL;
	
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		opening_error(argv);
	while ((line_size = _getline(&buf, &len, fp)) != EOF)
	{
		token = strtok(buf, "\n\t\r ");
		if (token == NULL)
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\a\r ;:");
			if (token == NULL || is_number(token) == -1)
				not_int_err(line_counter);
			number = atoi(token);
			
			func = get_op(command, line_counter);
			func(&top, line_counter);
		}
		else
		{
			func = get_op(token, line_counter);
			func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	free_stack(top);
}
/**
 * is_comment - a function that checks if the line is a comment
 * @token: the string to check
 * @line_number: the number of the line
 * Return: -1 if a comment or 1 if not a comment
 */
int is_comment(char *token, int line_number)
{
	if (token == NULL || token[0] == '#')
	{
		line_number++;
		return (1);
	}
	return (-1);
}

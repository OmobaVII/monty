#include "monty.h"
/**
 * _getline - a function that works like getline
 * @lineptr: the pointer to the line
 * @n: the size of the read line
 * @stream: the file to read from
 * Return: -1 for fail and 1 for success
 */
ssize_t _getline(char** lineptr, size_t* n, FILE* stream)
{
	char* line = NULL;
	size_t bufsize = 0;
	int c; 
	size_t i = 0;
	char *new_line;

	while ((c = getc(stream)) != '\n' && c != EOF)
	{
		if (i == bufsize)
		{
			bufsize += 64;
			new_line = malloc(bufsize);
			if (!new_line)
			{
				return (-1);
			}
			if (line)
			{
				memcpy(new_line, line, i);
				free(line);
			}
			line = new_line;
		}
		line[i++] = c;
	}
	if (i == 0 && c == EOF)
	{
		return (-1);
	}
	if (i == bufsize)
	{
		bufsize += 1;
		new_line = malloc(bufsize);
		if (!new_line)
		{
			return (-1);
		}
		if (line)
		{
			memcpy(new_line, line, i);
			free(line);
		}
		line = new_line;
	}
	line[i] = '\0';
	*lineptr = line;
	*n = bufsize;
	return (i);
}

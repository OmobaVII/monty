#include "monty.h"

#define BUFFER_SIZE 10000
/**
 * main - the entry to the program
 * @argc: the number of arguments
 * @argv: the arguments
 * Return: 0 for success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_read(argv);
	return (0);
}

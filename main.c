#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: monty file location
 * Return: 0 on success
 */
stack_t *stack = NULL;

int main(int ac, char *av[])
{
	int line_number = 0;
	char *line = NULL, *trimmed_line;
	size_t line_length = 0;
	int read = 1;
	FILE *file;


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		read = getline(&line, &line_length, file);

		line_number++;

		if (read == -1)
			break;

		trimmed_line = strtok(line, "\t\n ");
		if (trimmed_line != NULL && *trimmed_line != '\0' && *trimmed_line != '#')
			execute(trimmed_line, &stack, line_number);

	}
	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}

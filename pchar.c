#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int ascii_value = (*stack)->n;

		if (ascii_value < 0 || ascii_value > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", (char)ascii_value);
	}
}

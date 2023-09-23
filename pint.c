#include "monty.h"
/**
 * pint - print first elt in stack
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number in the Monty file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

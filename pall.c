#include "monty.h"

/**
 * pall -  function is to display the contents of the stack.
 * @stack: A double pointer to the top of the stack
 * @line_number: the current line number in the bytecode file
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	for (current = *stack; current != NULL; current = current->next)
		printf("%d\n", current->n);
}

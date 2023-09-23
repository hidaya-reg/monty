#include "monty.h"
/**
 * pop - pop elt from stack
 * @stack: stack
 * @line_number: line_number in monty file
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp = *stack;

		*stack = (*stack)->next;
		free(temp);
	}
}

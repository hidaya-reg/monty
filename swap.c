#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int temp = (*stack)->n;

		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}

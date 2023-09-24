#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

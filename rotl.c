#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack, *second;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	
	second = (*stack)->next;
	second->prev = NULL;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = second;
}

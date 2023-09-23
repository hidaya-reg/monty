#include "monty.h"
/**
 * free_stack - free stack
 * @stack: stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

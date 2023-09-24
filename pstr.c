#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *c = *stack;

	(void)line_number;
	while (c != NULL && c->n != 0 && c->n >= 0 && c->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

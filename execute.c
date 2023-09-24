#include "monty.h"
/**
 * execute - Execute the Monty opcode.
 * @opcode: The Monty opcode to execute
 * @stack: Pointer to the stack
 * @line_number: The current line number in the Monty file
 * Return: 0 on success, 1 on failure
 */
int execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

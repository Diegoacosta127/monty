#include "monty.h"

/**
 * nop - useful function
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void pchar(stack_t **stack, unsigned int line)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u : can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar(10);
}

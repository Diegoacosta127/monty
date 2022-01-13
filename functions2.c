#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void add(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line);
}
/**
 * sub - subtracts the top element of stack from second top element of stack
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void sub(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line);
}
/**
 * div - divides the second top element of stack by top element of stack
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void divide(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u:can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line);
}
/**
 * mul - multiplies second top element of stack with top element of stack
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void mul(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack to short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line);
}
/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void mod(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line);
}

#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *numstr;
	int i;
	stack_t *new;

	numstr = strtok(NULL, " ");
	if (!numstr)
		numstr = "a";
	for (i = 0; numstr[i]; i++)
	{
		if (numstr[i] >= '0' && numstr[i] <= '9')
			continue;
		else
		{
			fprintf(stderr,
			"L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(numstr);
	new->prev = NULL;
	new->next = NULL;
	if (!(*stack))
	{
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints all values on the stack, starting from top of the stack
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	if (!aux)
		return;
	while (aux)
	{
		fprintf(stdout, "%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * pint - prints value on the top of the stack
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack.
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->next))
	{
		*stack = NULL;
		free(*stack);
		return;
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: head of stack (double linked list)
 * @line: line number in file
 */
void swap(stack_t **stack, unsigned int line)
{
	int auxn, len = 0;
	stack_t *aux = *stack;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	auxn = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = auxn;
}

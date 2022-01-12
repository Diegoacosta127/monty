#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (!new)
		exit(EXIT_FAILURE);
	new->n = atoi(strtok(NULL, " "));
	new->prev = NULL;
	new->next = NULL;
	if (!new->n)
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "Can't pall");
		exit(EXIT_FAILURE);
	}
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * pint - prints all values on the stack, starting from the the bottom
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d", (*stack)->n);
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
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: head of stack (double linked list)
 * @line_number: line number in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int aux1, aux2, len = 0;
	stack_t *aux = *stack;

	while (aux->next)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		printf("L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	aux1 = (*stack)->n;
	aux2 = (*stack)->next->n;
	(*stack)->n = aux2;
	(*stack)->next->n = aux1;
}

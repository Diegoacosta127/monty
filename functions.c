#include "monty.h"
/**
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		return (NULL);
	}
	new->n = atoi(strtok(NULL, " "));
	new->prev = NULL;
	new->next = NULL;
	if (!(new->n))
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack))
	{
		*stack = new;
		return (*stack);
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
/**
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	if (!aux)
	{
		fprintf(stderr, "Can't pall")
		exit(EXIT_FAILURE);
	}
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d", *(stack)->n;);
}
/**
  */
void pop(stack_t **stack, unsigned int line_number)
{
	if(!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = *(stack)->next;
	free(*(stack)->prev);
	*(stack)->prev = NULL;
}






















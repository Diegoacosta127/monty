#include "monty.h"
/**
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void)line_number;
	if (!new)
	{
		return (NULL);
	}
	new->n = atoi(strtok(NULL, " "));
	new->prev = NULL;
	new->next = NULL;
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

	if (!aux)
	{
		fprintf(stderr, "Error")
		exit(EXIT_FAILURE);
	}
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

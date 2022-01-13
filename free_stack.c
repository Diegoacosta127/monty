#include "monty.h"
/**
  * free_stack - frees a stack_t list
  * @stack: pointer to stack_t list
  * Return: void
  */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		if (stack->next)
			free_stack(stack->next);
		free(stack);
	}
}

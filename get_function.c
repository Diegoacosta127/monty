#include "monty.h"
/**
  * get_function - checks function in a certain line
  * @list: pointer to pointer of char
  * Return: void
  */
void *get_function(char **list)
{
	unsigned int position, i;
	char *command;
	stack_t *stack = NULL;
	instruction_t instr_list[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pop", NULL},
		{"pint", NULL},
		{"swap", NULL},
		{"add", NULL},
		{NULL, NULL}
	}

	for (position = 0; list[position]; position++)
	{
		i = 0;
		command = strtok(list[position], " ");
		while (instr_list[i].opcode)
		{
			if (strcmp(instr_list[i].opcode, command) == 0)
				instr_list[i].f(&stack, pos);
			i++;
		}
	}
	return (NULL);
}

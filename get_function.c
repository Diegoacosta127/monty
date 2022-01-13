#include "monty.h"
/**
  * get_function - checks function in a certain line
  * @list: pointer to pointer of char
  * Return: void
  */
void get_function(char **list)
{
	unsigned int position, i;
	char *command;
	stack_t *stack = NULL;
	/* {opcode, function} */
	instruction_t instr_list[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	for (position = 0; list[position]; position++)
	{
		i = 0;
		command = strtok(list[position], " ");
		/*printf("2strtok - %s\n", command);*/
		/* if line starts with a space char at this point, skip*/
		if (command == 0)
			continue;
		/*for each line.opcode in instructions struct*/
		while (instr_list[i].opcode)
		{
			/*if command in line matches command in stuct opcode*/
			if (strcmp(instr_list[i].opcode, command) == 0)
				instr_list[i].f(&stack, position + 1);
			i++;
		}
	}
}

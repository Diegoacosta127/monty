#include "monty.h"
/**
  * get_function - checks function in a certain line
  * @list: pointer to pointer of char
  */
void *get_function(char **list)
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
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{NULL, NULL}
	};

	for (position = 0; list[position]; position++)
	{
		i = 0;
		command = strtok(list[position], " ");
		// printf("2strtok - %s\n", command);
		/*for each line.opcode in instructions struct*/
		while (instr_list[i].opcode)
		{
			/*if command in line matches command in stuct opcode*/
			if (strcmp(instr_list[i].opcode, command) == 0)
				instr_list[i].f(&stack, position);
			i++;
		}
	}
}

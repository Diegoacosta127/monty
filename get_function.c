#include "monty.h"
/**
  * get_function - checks function in a certain line
  * @list: pointer to pointer of char
  * @stack: pointer to double linked list
  */
void get_function(char **list, stack_t *stack)
{
	unsigned int pos, i;
	char *command;
	/* {opcode, function} */
	instruction_t instr_list[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"pint", pint},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"#", nop}, {NULL, NULL}
	};

	for (pos = 0; list[pos]; pos++)
	{
		i = 0;
		command = strtok(list[pos], "\t ");
		/*printf("2strtok - %s\n", command);*/
		/* if line starts with a space char at this point, skip*/
		if (command == 0)
			continue;
		while (instr_list[i].opcode)
		{
			if (strcmp(instr_list[i].opcode, command) == 0)
			{
				instr_list[i].f(&stack, pos + 1);
				break;
			}
			else
			{
				i++;
				if (!(instr_list[i].opcode))
				{
					fprintf(stderr,
					"L%u: unknown instruction %s\n",
					pos + 1, command);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	free_stack(stack);
}

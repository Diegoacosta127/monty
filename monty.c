#include "monty.h"
/**
  * main - entry point of the program
  * @argc: argument counter
  * @argv: argument vector
  * Return: always 0
  */
int main(int argc, char *argv[])
{
	int line;
	size_t len = 1024;
	char *command, *buf = NULL;
	FILE *fd;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (line = 1; getline(&buf, &len, fd) != -1; line++)
	{
		buf[strlen(buf) - 1] = 0;
		command = strtok(buf, " \t");
		if (!command)
		{
			free(buf);
			buf = NULL;
			continue;
		}
		if (command[0] == '#')
		{
			free(buf);
			buf = NULL;
			continue;
		}
		get_function(command, line, &stack);
		free(buf);
		buf = NULL;

	}
	free(buf), buf = NULL, fclose(fd), free_stack(stack);
	return (0);
}

/**
  * get_function - checks function in a certain line
  * @command: monty opcode
  * @line: line num of file
  * @stack: pointer to double linked list
  */
void get_function(char *command, int line, stack_t **stack)
{
	int i;
	/* {opcode, function} */
	instruction_t instr_list[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"pint", pint},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"#", nop}, {NULL, NULL}
	};

	for (i = 0; instr_list[i].opcode; i++)
	{
		if (strcmp(instr_list[i].opcode, command) == 0)
		{
			instr_list[i].f(stack, line);
			break;
		}
	}
	if (!(instr_list[i].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
		line, command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

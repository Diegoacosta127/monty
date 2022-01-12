#include "monty.h"
/**
  * main - entry point of the program
  * @argc: argument counter
  * @argv: argument vector
  * Return: always 0
  */
int main(int argc, char *argv[])
{
	int fd, i, j;
	char buf[1024], *tok[1024];

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, buf, 1024);
	tok[0] = strtok(buf, "\n");
	//printf("Hizo un strtok\n");
	for (i = 0; *(tok + i);)
	{
		i++;
		*(tok + i) = strtok(NULL, "\n");
	}
	//printf("tokenizó todo el archivo\n");
	for (j = 0; *(tok + j); j++)
	{
		printf("voy a entrar a get_function\n");
		get_function(tok);

	}
	return (0);
}

#include "monty.h"
/**
  * main - entry point of the program
  * @argc: argument counter
  * @argv: argument vector
  * Return: always 0
  */
int main(int argc, char *argv[])
{
	int fd, i, sizef;
	char buf[1024], *tok[1024];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	sizef = read(fd, buf, 1024);
	buf[sizef] = 0;
	/*printf("buffer - %s\n", buf);*/
	/*printf("--------------\n"); */
	tok[0] = strtok(buf, "\n");
	/*printf("strtok - %s\n", tok[0]);*/
	for (i = 0; tok[i];)
	{
		i++;
		tok[i] = strtok(NULL, "\n");
		/*printf("strtok - %s\n", tok[i]);*/
	}
	/*printf("voy a entrar a get_function\n");*/
	get_function(tok);
	return (0);
}

#include "monty.h"

/**
 * main - Hi Mr. Monty how are you?
 * @argc: The ticker for the arguments who come in
 * @argv: The arguments themselves and what they are worth
 * Return: Sometimes 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", (av[1]));
		return (EXIT_FAILURE);
	}
	return (0);
}

#include "monty.h"

/**
 * main - Hi Mr. Monty how are you?
 * @argc: The ticker for the arguments who come in
 * @argv: The arguments themselves and what they are worth
 * Return: Sometimes 0 (on Success).
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", (argv[1]));
		return (EXIT_FAILURE);
	}
	return (0);
}
/**
 *get_func - get a func of some kind
 *@stack: the whole stack
 *@l: the line number
 *@code: the code being brought in
 *Return: what ever func is right
 */

void (*get_func(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};
	int i = 0;

	while (strcmp(code, instruction[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, code)
			free_stack(stack);
			error();
		}
	}
	return (instruction[i].f);
}
/**
 *error - error is bad
 *Return: an exit
 */
void error(void)
{
	fclose(file);
	exit(EXIT_FAILURE);
}



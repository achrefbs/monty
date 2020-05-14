#include "monty.h"
void inst(char **s, stack_t **stack, unsigned int n)
{
	int i = 0;
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	if (strcmp(s[0], "push") == 0 && s[1] == NULL && isdigit(s[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		free(s[1]);
		free(s[0]);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (s[1] != NULL)
		value = atoi(s[1]);
	while (inst[i].opcode != NULL)
	{
		if (strcmp(inst[i].opcode, s[0]) == 0)
			inst[i].f(stack, n);
		i++;
	}
}
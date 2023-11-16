#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @count: line_counter
* @file: poiner to monty file
* @content: line content
* Return: 1
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_s}, {"pall", pall_s}, {"pint", pint_s},
				{"pop", pop_s},
				{"swap", swap_s},
				{"add", add_s},
				{"nop", nop_s},
				{"sub", sub_s},
				{"div", div_s},
				{"mul", mul_s},
				{"mod", mod_s},
				{"pchar", pchar_s},
				{"pstr", pstr_s},
				{"rotl", rotl_s},
				{"rotr", rotr_s},
				{"queue", queue_s},
				{"stack", stack_s},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	chain.args = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

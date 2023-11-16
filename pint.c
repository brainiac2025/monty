#include "monty.h"
/**
 * pint_s - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void pint_s(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

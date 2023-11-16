#include "monty.h"
/**
 * swap_s - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void swap_s(stack_t **head, unsigned int count)
{
	stack_t *hd;
	int len = 0, aux;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->n;
	hd->n = hd->next->n;
	hd->next->n = aux;
}

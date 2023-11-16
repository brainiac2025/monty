#include "monty.h"
/**
 * pop_s - prints the top
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void pop_s(stack_t **head, unsigned int count)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}

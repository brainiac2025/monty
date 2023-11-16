#include "monty.h"

/**
 * pchar_s - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void pchar_s(stack_t **head, unsigned int count)
{
	stack_t *hd;

	hd = *head;
	if (!hd)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (hd->n > 127 || hd->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hd->n);
}

/**
 * pstr_s - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void pstr_s(stack_t **head, unsigned int count)
{
	stack_t *hd;
	(void)count;

	hd = *head;
	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
		{
			break;
		}
		printf("%c", hd->n);
		hd = hd->next;
	}
	printf("\n");
}

#include "monty.h"
/**
 * push_s - add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void push_s(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (chain.args)
	{
		if (chain.args[0] == '-')
			j++;
		for (; chain.args[j] != '\0'; j++)
		{
			if (chain.args[j] > 57 || chain.args[j] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(chain.file);
			free(chain.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(chain.args);
	if (chain.lifi == 0)
		addnode_s(head, n);
	else
		addqueue_s(head, n);
}

/**
 * pall_s - prints the stack
 * @head: stack head
 * @count: unused
 * Return: void
 */
void pall_s(stack_t **head, unsigned int count)
{
	stack_t *hd;
	(void)count;

	hd = *head;

	if (hd == NULL)
		return;

	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}

#include "monty.h"

/**
 * add_s - adds the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void add_s(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->n + hd->next->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}

/**
  *sub_s- sustration
  *@head: stack head
  *@count: line_number
  *Return: void
 */
void sub_s(stack_t **head, unsigned int count)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
 * div_s - divides the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void div_s(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = hd->next->n / hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}

/**
 * mul_s - multiplies the top two elements of the stack.
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void mul_s(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->next->n * hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}

/**
 * mod_s - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void mod_s(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(chain.file);
		free(chain.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = hd->next->n % hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}

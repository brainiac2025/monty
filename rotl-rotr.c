#include "monty.h"

/**
  *rotl_s- rotates the stack to the top
  *@head: stack head
  *@count: line_number
  *Return: void
 */
void rotl_s(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
  *rotr_s- rotates the stack to the bottom
  *@head: stack head
  *@count: line_number
  *Return: void
 */
void rotr_s(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

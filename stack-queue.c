#include "monty.h"
/**
 * stack_s - prints the top
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void stack_s(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	chain.lifi = 0;
}

/**
 * queue_s - prints the top
 * @head: stack head
 * @count: line_number
 * Return: void
*/
void queue_s(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	chain.lifi = 1;
}

/**
 * addqueue_s - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: void
*/
void addqueue_s(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * addnode_s - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: void
*/
void addnode_s(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

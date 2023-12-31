#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct chain_s - variables -args, file, line content
 * @args: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct chain_s
{
	char *args;
	FILE *file;
	char *content;
	int lifi;
}  chain_t;


extern chain_t chain;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_s(stack_t **head, unsigned int number);
void pall_s(stack_t **head, unsigned int number);
void pint_s(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop_s(stack_t **head, unsigned int counter);
void swap_s(stack_t **head, unsigned int counter);
void add_s(stack_t **head, unsigned int counter);
void nop_s(stack_t **head, unsigned int counter);
void sub_s(stack_t **head, unsigned int counter);
void div_s(stack_t **head, unsigned int counter);
void mul_s(stack_t **head, unsigned int counter);
void mod_s(stack_t **head, unsigned int counter);
void pchar_s(stack_t **head, unsigned int counter);
void pstr_s(stack_t **head, unsigned int counter);
void rotl_s(stack_t **head, unsigned int counter);
void rotr_s(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode_s(stack_t **head, int n);
void addqueue_s(stack_t **head, int n);
void queue_s(stack_t **head, unsigned int counter);
void stack_s(stack_t **head, unsigned int counter);
#endif

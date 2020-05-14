#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;
    (void) line_number;
    new = malloc(sizeof(stack_t));
        if(new == NULL)
        {
            fprintf(stderr,"Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
    new->n = value;
    new->next = NULL;
    new->prev = *stack;
    if (*stack != NULL)
    (*stack)->next = new;
    *stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    while ((*stack))
    {
        printf("%d\n",(*stack)->n);
        *stack = (*stack)->prev;
    }
    
}

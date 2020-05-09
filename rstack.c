#include <stdio.h>
#include <stdlib.h>

// LIFO
// Last In First Out
// El último que entra, es el primero que sale

// O-O-O-O
// 1-2-3-4

typedef struct node_t
{
    int value;
    void *next;
} node_t;

typedef struct stack_t
{
    unsigned int size;
    node_t *top;
} stack_t;

void push(stack_t *stack, int value)
{
    if (stack == NULL)
        return;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    // new_node->next = NULL;

    if (stack->top == NULL)
        stack->top = new_node;
    else
    {
        new_node->next = stack->top;
        stack->top = new_node;
    }

    stack->size++;
}

int pop(stack_t *stack)
{
    if (stack == NULL)
        return -1;
    else if (stack->size == 0)
        return -1;

    node_t *tmp = stack->top;
    int value = tmp->value;

    stack->top = tmp->next;
    free(tmp);
    stack->size--;

    return value;
}

int main(const int argc, const char *argv[])
{
    stack_t mi_pila = {0};

    for (int i = 0; i < 10; i++)
    {
        push(&mi_pila, i);
        printf("El valor %d fue insertado a la cola.\n", i);
    }

    printf("\n\nSACANDO\n\n");

    while (mi_pila.size > 0)
    {
        int value = pop(&mi_pila);
        printf("El valor %d fue sacado de la pila.\n", value);
    }

    return 0;
}
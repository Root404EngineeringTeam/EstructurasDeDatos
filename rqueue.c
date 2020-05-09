// FIFO
// First In First Out
// El primero que entra, es el primero que sale

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    float value;
    void *next;
} node_t;

typedef struct queue_t
{
    unsigned int size;
    node_t *root;
} queue_t;

void add(queue_t *queue, float value)
{
    if (queue == NULL)
        return;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;

    if (queue->root == NULL)
        queue->root = new_node;
    else
    {
        node_t *tmp = queue->root;
        node_t *cursor = tmp;

        while (tmp != NULL)
        {
            tmp = tmp->next;
            if (tmp != NULL)
                cursor = tmp;
        }

        cursor->next = new_node;
    }

    queue->size++;
}

float pull(queue_t *queue)
{
    if (queue == NULL)
        return -1.0f;
    else if (queue->size == 0)
        return -1.0f;

    node_t *tmp = queue->root;
    queue->root = tmp->next;
    float value = tmp->value;

    free(tmp);
    queue->size--;

    return value;
}

int main(const int argc, const char *argv[])
{
    queue_t cola = {0};

    for (float i = 0.0f; i < 10.0f; i += 0.5f)
    {
        add(&cola, i);
        printf("El valor %f fue agregado al final de la cola.\n", i);
    }

    printf("\n\nSACANDO\n\n");

    while (cola.size > 0)
    {
        float value = pull(&cola);
        printf("El valor %f fue removido de la cola.\n", value);
    }

    return 0;
}
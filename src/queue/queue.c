#include "queue.h"

queue *queue_create(size_t size, size_t element_size)
{
    queue *q;
    size_t i;

    q = malloc(sizeof(queue));

    if(check_nullptr(q, QUEUE_ERROR_MALLOC))
    {
        return NULL;
    }

    q->elements = malloc(size*sizeof(void *));

    if(check_nullptr(q->elements, QUEUE_ERROR_MALLOC))
    {
        free(q);
        return NULL;
    }

    for(i=0; i<size; i++)
    {
        q->elements[i] = malloc(element_size); 

        if(check_nullptr(q->elements[i], QUEUE_ERROR_MALLOC))
        {
            free(q);
            free(q->elements);

            int j;
            for(j=0; j<i; j++)
            {
                free(q->elements[j]);
            }
        }
    }

    q->head = 0;
    q->tail = 0;
    q->full = false;
    q->empty = true;
    q->element_size = element_size;
    q->size = size;

    return q;
}

void queue_destroy(queue **q)
{
    if(check_nullptr(q, QUEUE_ERROR_NULLPTR))
    {
        return;
    }
    if(check_nullptr(*q, QUEUE_ERROR_NULLPTR))
    {
        return;
    }

    size_t i;
    for(i=0; i<(*q)->size; i++)
    {
        free(*((*q)->elements+i));
    }
    free((*q)->elements);
    free(*q);

    *q = NULL;
}

bool queue_push(queue *q, void *element)
{
    if(check_nullptr(q, QUEUE_ERROR_NULLPTR))
    {
        return false;
    }

    if(queue_full(q))
    {
        printf("QUEUE FULL\n");
        return false;
    }

    q->empty = false;
    q->head = (q->head+1)%q->size;

    if(q->head == q->tail) q->full = true;

    memcpy(*(q->elements + q->head), element, q->element_size);

    return true;
}

void *queue_pop(queue *q)
{
    if(check_nullptr(q, QUEUE_ERROR_NULLPTR))
    {
        return NULL;
    }

    void *element;

    if(queue_empty(q))
    {
        printf("QUEUE EMPTY\n");
        return NULL;
    }

    q->tail = (q->tail+1)%q->size;

    if(q->head == q->tail) q->empty = true;
    else if(q->full) q->full = false;

    element = *(q->elements + q->tail);

    return element;
}

void *queue_front(queue *q)
{
    return NULL;
}

bool queue_empty(queue *q)
{
    if(!check_nullptr(q, QUEUE_ERROR_NULLPTR))
    {
        return q->empty;
    }
    return false;
}

bool queue_full(queue *q)
{
    if(!check_nullptr(q, QUEUE_ERROR_NULLPTR))
    {
        return q->full;
    }
    return true;
}

bool check_nullptr(void *q, char *error)
{
    bool status = false;
    if(q == NULL)
    {
        fprintf(stderr, "%s", error);
        status = true;
    }

    return status;
}
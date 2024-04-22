#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QUEUE_ERROR_NULLPTR "[QUEUE]: Error, NULL Pointer"
#define QUEUE_ERROR_MALLOC  "[QUEUE]: Error, Unable to allocate memory"

typedef struct
{
    bool full;
    bool empty;
    size_t tail;
    size_t head;
    size_t size;
    size_t element_size;
    void **elements;
}queue;

queue *queue_create(size_t size, size_t element_size);
void queue_destroy(queue **q);
bool queue_push(queue *q, void *element);
void *queue_pop(queue *q);
void *queue_front(queue *q);
bool queue_empty(queue *q);
bool queue_full(queue *q);
bool check_nullptr(void *q, char *error);
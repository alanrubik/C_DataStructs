#include "queue.h"

#define QUEUE_SIZE  100

bool queue_create_test(void);
bool queue_destroy_test(void);

int main(void)
{
    int errors = 0;

    errors += queue_create_test() ? 0:1;
    errors += queue_destroy_test() ? 0:1;

    if(errors == 0)
    {
        printf("All tests passed!\n");
    }
    else
    {
        printf("%d tests failed!\n", errors);
    }

    return 0;
}

bool queue_create_test(void)
{
    queue *q;
    int  errors = 0;

    q = queue_create(QUEUE_SIZE, sizeof(int));

    errors += q != NULL ? 0:1;
    errors += q->size == QUEUE_SIZE ? 0:1;
    errors += q->element_size == sizeof(int) ? 0:1;
    errors += !queue_full(q) ? 0:1;
    errors += queue_empty(q) ? 0:1;
    
    return errors == 0;
}

bool queue_destroy_test(void)
{
    queue *q;

    q = queue_create(QUEUE_SIZE, sizeof(int));
    queue_destroy(&q);

    return q == NULL;
}
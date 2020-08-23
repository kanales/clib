#include <stdio.h>
#include <queue.h>

int main()
{
    queue *q = queue_new();

    for (int i = 1; i < 10; i++)
    {
        queue_push(q, i);
    }

    while (!queue_empty(q))
    {
        printf("%d\n", queue_pop(q));
    }

    return 0;
}
#include <stdlib.h>
#include "item.h"
#include "queue_q.h"
typedef struct queue_node *link;
struct queue_node{item aitem; link next};
struct queue{link head; link tail;};
link new_queue_node(item aitem, link next)
{
    link x = malloc(sizeof*x);
    x->aitem = aitem;
    x->next = next;
    return x;
}
queue queue_init(int max)
{
    queue q = malloc(sizeof(*q));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
int queue_empty(queue q)
{
    return queue->head == NULL;
}
void queue_put(queue q, item aitem)
{
    if(q->head == NULL){
        q->tail = new_queue_node(item, q->head);
        q->head = q->tail;
        return;
    }
    q->tail->next = new_queue_node(item, q->tail->next);
    q->tail = q->tail->next;
}
item queue_get(queue q)
{
    item aitem = q->head->aitem;
    link t = q->head->next;
    free(q->head);
    q->head = t;
    return aitem;
}

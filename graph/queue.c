#include <stdlib.h>
#include "queue.h"
static snode *qhead, *qtail;
int queue_empty(void)
{
    return qhead == NULL;
}
void queue_put(item data)
{
    if(queue_empty()){
        qhead = qtail = list_insert(qhead, data);
        return;
    }
    qtail->next = list_insert(qtail->next, data);
    qtail = qtail->next;
}
item queue_get(void)
{
    item data = qhead->data;
    qhead = list_delete(qhead);
    return data;
}

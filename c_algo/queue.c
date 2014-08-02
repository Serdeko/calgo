#include <stdlib.h>
#include "item.h"
#include "queue.h"
typedef struct queue_node *link;
struct queue_node{item aitem; link next;};
static link g_head, g_tail;
static link new_queue_node(item aitem, link next)
{
    link tmp = malloc(sizeof*tmp);
    tmp->aitem = aitem;
    tmp->next = next;
    return tmp;
}
void queue_init(int max_num)
{
    g_head = NULL;
}
int queue_empty(void)
{
    return g_head == NULL;
}
void queue_put(item aitem)
{
    if(g_head == NULL){
        g_head = (g_tail = new_queue_node(aitem, g_head));
        return;
    }
    g_tail->next = new_queue_node(aitem, g_tail->next);
    g_tail = g_tail->next;
}
item queue_get(void)
{
    item aitem = g_head->aitem;
    link tmp = g_head->next;
    free(g_head);
    g_head = tmp;
    return aitem;
}
/*
#include <stdio.h>
void queue_print(void)
{
    link tmp = g_head;
    while(tmp != NULL){
        printf("%d\n", tmp->aitem);
        tmp = tmp->next;
    }
}
int main(void)
{
    queue_init(10);
    queue_put(10);
    queue_put(20);
    queue_put(30);
    queue_put(2);
    printf("%d\n", queue_get());
    queue_print();
    return 0;
}
*/

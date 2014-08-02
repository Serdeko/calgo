#include <stdlib.h>
#include "item.h"
#include "queue.h"
static item *g_q;
static int g_num, g_head, g_tail;
void queue_init(int max_num)
{
    g_q = malloc((max_num+1)*sizeof*g_q);
    g_num = max_num+1;
    g_head = g_num;
    g_tail = 0;
}
int queue_empty(void)
{
    return g_head%g_num == g_tail;
}
void queue_put(item aitem)
{
    g_q[g_tail++] = aitem;
    g_tail = g_tail%g_num;
}
item queue_get(void)
{
    g_head = g_head%g_num;
    return g_q[g_head++];
}
/*//Î´¿¼ÂÇ´óÐ¡£¬FIFO
static item *g_q;
static int g_num, g_head;
void queue_init(int max_num)
{
    g_q = malloc(max_num*sizeof*g_q);
    g_num = 0;
    g_head = 0;
}
int queue_empty(void)
{
    return g_num == 0;
}
void queue_put(item aitem)
{
    g_q[g_num++] = aitem;
}
item queue_get(void)
{
    return g_q[g_head++];
}*/
/*
#include <stdio.h>
void queue_print(void)
{
    int i;
    for(i = g_head; i < g_num; i++){
        printf("%d\n", g_q[i]);
    }
}
int main(void)
{
    queue_init(10);
    queue_put(5);
    queue_put(8);
    queue_put(11);
    queue_get();
    printf("%d, %d\n", g_head, g_num);
    queue_print();
    return 0;
}
*/

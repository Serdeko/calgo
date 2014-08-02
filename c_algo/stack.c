/*栈的链表实现*/
#include <stdlib.h>
#include "item.h"
#include "stack.h"
typedef struct stack_node *link;
struct stack_node{item aitem; link next;};
static link g_head;

static link new_stack_node(item aitem, link next)
{
    link tmp = malloc(sizeof*tmp);
    tmp->aitem = aitem;
    tmp->next = next;
    return tmp;
}
void stack_init(int max_num)
{
    g_head = NULL;
}
int stack_empty(void)
{
    return g_head == NULL;
}
void stack_push(item aitem)
{
    g_head = new_stack_node(aitem, g_head);
}
item stack_pop(void)
{
    item aitem = g_head->aitem;
    link tmp = g_head->next;
    free(g_head);
    g_head = tmp;
    return aitem;
}
/*
#include <stdio.h>
void stack_print(void)
{
    link tmp = g_head;
    while(tmp != NULL){
        printf("%d\n", tmp->aitem);
        tmp = tmp->next;
    }
}
int main(void)
{
    stack_init(10);
    stack_push(5);
    stack_push(15);
    stack_push(1111);
    stack_pop();
    stack_print();
    return 0;
}
*/

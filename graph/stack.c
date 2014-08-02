#include <stdlib.h>
#include "stack.h"
#include "list.h"
static snode *head;
int stack_empty(void)
{
    return !head; // head == NULL
}
void stack_push(item data)
{
    head = list_insert(head, data);
}
item stack_pop(void)
{
    if(stack_empty())
        return 0;
    item data = head->data;
    head = list_delete(head);
    return data;
}
item stack_top(void)
{
    if(stack_empty())
        return 0;
    return head->data;
}

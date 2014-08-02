#include <stdlib.h>
#include "stack.h"
static lnode *shead;
int stack_empty(void)
{
    return !shead;
}
void stack_push(item data)
{
    shead = list_insert(shead, data);
}
item stack_pop(void)
{
    if(stack_empty())
        return NULL;
    item data = shead->data;
    shead = list_delete(shead);
    return data;
}
item stack_top(void)
{
    if(stack_empty())
        return NULL;
    return shead->data;
}

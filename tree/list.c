#include <stdlib.h>
#include "list.h"
int list_empty(lnode *link)
{
    return !link;
}
lnode *list_insert(lnode *link, item data)
{
    lnode *tmp = malloc(sizeof(lnode));
    tmp->data = data;
    tmp->next = link;
    return tmp;
}
lnode *list_delete(lnode *link)
{
    if(list_empty(link))
        return NULL;
    lnode *tmp = link->next;
    free(link);
    return tmp;
}


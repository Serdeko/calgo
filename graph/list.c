#include <stdlib.h>
#include "list.h"
int list_empty(snode *link)
{
    return link == NULL;
}
snode *list_insert(snode *link, item data)
{
    snode *tmp = malloc(sizeof(snode));
    tmp->data = data;
    tmp->next = link;
    return tmp;
}
snode *list_delete(snode *link)
{
    snode *tmp = link->next;
    free(link);
    link = NULL;
    return tmp;
}

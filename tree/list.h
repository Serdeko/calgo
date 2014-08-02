#ifndef __LIST_H__
#define __LIST_H__
#include "tree.h"
#define item tree*
typedef struct lnode{
    item data;
    struct lnode *next;
}lnode;
int list_empty(lnode *link);
lnode *list_insert(lnode *link, item data);
lnode *list_delete(lnode *link);
#endif // __LIST_H__

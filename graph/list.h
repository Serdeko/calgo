#ifndef __LIST_H__
#define __LIST_H__

//#include "tree.h"
#define item int

typedef struct snode{
    item data;
    struct snode *next;
}snode;

int list_empty(snode *link);
snode *list_insert(snode *link, item data);
snode *list_delete(snode *link);

#endif // __LIST_H__

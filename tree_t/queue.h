#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "list.h"

int queue_empty(void);
void queue_put(item data);
item queue_get(void);

#endif // __QUEUE_H__

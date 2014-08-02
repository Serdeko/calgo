#ifndef __STACK_H__
#define __STACK_H__
#include "list.h"
int stack_empty(void);
void stack_push(item data);
item stack_pop(void);
item stack_top(void);
#endif // __STACK_H__

#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__

void stack_init(void);
int stack_is_empty(void);
int static_is_full(void);
void stack_push(int t);
int stack_pop(void);

void stack_array_test(void);

#endif // __STACK_ARRAY_H__

#include <stdio.h>
#include "stack_array.h"

void stack_array_test(void)
{
    stack_init();
    stack_push(3);
    stack_push(2);
    stack_push(4);
    stack_push(8);
    stack_push(9);

    printf("%d\n", stack_pop());
    printf("%d\n", stack_pop());
}

/*数组形式实现栈*/
#include <stdlib.h>
#include "item.h"
#include "stack.h"
static item *g_s;
static int g_num;
/*栈初始化*/
void stack_init(int max_num)
{
    g_s = malloc(max_num * sizeof(*g_s));
    g_num = 0;
}
/*栈是否为空*/
int stack_empty(void)
{
    return g_num == 0;
}
/*压入栈中*/
void stack_push(item tmp)
{
    g_s[g_num++] = tmp;
}
/*弹出栈*/
item stack_pop(void)
{
    return g_s[--g_num];
}
/*
#include <stdio.h>
void stack_print(void)
{
    int i;
    for(i = 0; i < g_num; i++)
        printf("%d\n", g_s[i]);
}
int main(void)
{
    stack_init(10);
    stack_push(5);
    stack_push(8);
    stack_push(9);
    stack_pop();
    stack_print();
    return 0;
}
*/

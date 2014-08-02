/*������ʽʵ��ջ*/
#include <stdlib.h>
#include "item.h"
#include "stack.h"
static item *g_s;
static int g_num;
/*ջ��ʼ��*/
void stack_init(int max_num)
{
    g_s = malloc(max_num * sizeof(*g_s));
    g_num = 0;
}
/*ջ�Ƿ�Ϊ��*/
int stack_empty(void)
{
    return g_num == 0;
}
/*ѹ��ջ��*/
void stack_push(item tmp)
{
    g_s[g_num++] = tmp;
}
/*����ջ*/
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

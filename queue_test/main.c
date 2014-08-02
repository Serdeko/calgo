#include <stdio.h>
#include <stdlib.h>
static int *q;
static int g_left, g_right;//left队首，right队尾
int init_queue(int len)
{
    q = calloc(len, sizeof(int));
}
int is_empty(void)
{
     return (g_left == g_right);
}
int is_full(void)
{
    return ((g_right)%MAX_LEN == g_left);//5, g_left 1, g_right 0,  2, 1 , 0, 4
    //return ((g_right-g_left+1)%MAX_LEN == 0);
}
void put(int t)
{
    g_right = (g_right+1)%MAX_LEN;
    q[g_right] = t;
}
int get(void)
{
    int tmp = g_left;
    g_left = (g_left+1)%MAX_LEN; // 5个元素，g_left 4, MAX_LEN 5,
    return q[tmp];
}
int main()
{
    put(1);
    put(2);
    put(3);
    put(4);
    put(5);
    printf("%d, %d, %d\n", is_full(), g_left, g_right);
    printf("%d\n", get());
    printf("%d\n", get());
    put(6);
    put(7);
    printf("%d\n", get());
    printf("%d\n", get());
    printf("%d\n", get());
    printf("%d\n", get());
    printf("%d\n", get());

    return 0;
}

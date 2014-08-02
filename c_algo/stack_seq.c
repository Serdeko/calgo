#include <stdlib.h>
#include <string.h>
static int *s;
static char *t;
static int num;
void stack_init(int max)
{
    s = malloc(max*sizeof*s);
    t = malloc(max*sizeof*t);
    memset(t, 0, max);
    num = 0;
}
int stack_empty(void)
{
    return !num;
}
void stack_push(int aitem)
{
    if(t[aitem] == 1)
        return;
    s[num++] = aitem;
    t[aitem] = 1;
}
int stack_pop(void)
{
    num--;
    t[s[num]] = 0;
    return s[num];
}

#include <stdio.h>
#include <stdlib.h>
static int i = 3;
int fun()
{
    i--;
    if(i == 0)
        return 3;
    int i = fun();
    printf("aaa\n");
}
int main()
{
    printf("%d\n",fun());
    return 0;
}

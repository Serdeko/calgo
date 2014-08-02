#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
void get_float(float x)
{
    int *n = (int *)&x;
    printf("%x\n", *n);
}
void get_double(double x)
{
    long long *n = (long long *)&x;
    printf("%I64x\n", (long long)*n);
}
int main()
{
    //get_float(-0.0f);
    int i=0;
    float x=1.0;
    while(x!=0.0)
    {
        x*=0.1;
        ++i;
    }
    printf("%d\n", i);
    return 0;
}

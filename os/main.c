#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 10.02;
    float b = 10.00;
    float c = a-b;
    float d = 0.0000000000001f;
    if(d == 0)
        printf("abc\n");
    printf("%f\n", d);
    return 0;
}

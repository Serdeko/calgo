#include <stdio.h>
#include <stdlib.h>
#include "item.h"
double item_rand(void)
{
    return 1.0*rand()/RAND_MAX;
}
int item_scan(double *x)
{
    return sacnf("%f", x);
}
void item_show(double x)
{
    printf("%7.5f ", x);
}

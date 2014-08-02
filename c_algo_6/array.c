#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "array.h"
void rand_init(item a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        a[i] = item_rand();
}
void scan_init(item a[], int *n)
{
    int i = 0;
    for(i = 0; i < *n; i++)
        if(item_scan(&a[i]== EOF))
            break;
    *n = i;
}
void show(item a[], int left, int right)
{
    int i;
    for(i = left; i <= right; i++)
        item_show(a[i]);
    printf("\n");
}

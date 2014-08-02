#include <stdio.h>

int max(int a[], int start, int end)
{
    int u, v;
    int mid = (start+end)/2;
    u = max(a, start, mid);
    v = max(a, mid+1, end);
    return u>v?u:v;
}

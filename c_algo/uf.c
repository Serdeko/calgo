#include <stdlib.h>
#include "uf.h"
static int *id, *sz;
void uf_init(int num)
{
    int i;
    id = malloc(num*sizeof*id);
    sz = malloc(num*sizeof*sz);
    for(i = 0; i < num; i++){
        id[i] = i;
        sz[i] = 1;
    }
}
static int find(int x)
{
    int i = x;
    while(i != id[i])
        i = id[i];
    return i;
}
int uf_find(int p, int q)
{
    return (find(p) == find(q));
}
void uf_union(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if(i == j)
        return;
    if(sz[i] < sz[j]){
        id[i] = j;
        sz[j] += sz[i];
    }else{
        id[j] = i;
        sz[i] += sz[j];
    }
}


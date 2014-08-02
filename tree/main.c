#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define R (1<<8)
#define digit(a, b) (((a) >> (32-((b)+1)*8)) & (R-1))

void radix_lsd_sort(int *src, int left, int right)
{
    int i, j, k, count[R], tmp[right-left+1];
    for(k = 7; k >= 0; k--){
        for (j = 0; j < R; j++) count[j] = 0;
        for (i = left; i <= right; i++)
          count[digit(src[i], k) + 1]++;
        for (j = 1; j < R; j++)
          count[j] += count[j-1];
        for (i = left; i <= right; i++)
          tmp[count[digit(src[i], k)]++] = src[i];
        for (i = left; i <= right; i++) src[i] = tmp[i];
    }
}
int main()
{
    /*tree *btree = NULL;
    btree = tree_insert(btree, 12);
    btree = tree_insert(btree, 14);
    btree = tree_insert(btree, 8);
    btree = tree_insert(btree, 6);
    btree = tree_insert(btree, 11);
    btree = tree_insert(btree, 15);
    btree = tree_insert(btree, 9);
    btree = tree_insert(btree, 13);
    tree_traverse1(btree);
    printf("\n");
    tree_traverse2(btree);
    printf("\n");
    tree_traverse3(btree);
    printf("\n");
    tree_traverse_s3(btree);
    printf("\n");
    tree_traverse_cq(btree);
    printf("\n");
    printf("%d %d\n", tree_count(btree), tree_height(btree));
  */
    //printf("%d\n", count(3));
    int src[] = {52132, 92 ,1111, 32332, 33, 5555555, 88888};
    radix_lsd_sort(src, 0, 6);
    int i;
    for(i = 0; i < 7; i++)
        printf("%d ", src[i]);
    printf("\n");
    return 0;
}

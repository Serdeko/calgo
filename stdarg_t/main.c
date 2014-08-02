#include <stdio.h>
#include <stdlib.h>
#define exch(A, B) { int t = A; A = B; B = t; }
/*
void fixDown(int a[], int k, int len)
{
    int j;
    while (2*k <= len){
        j = 2*k;
        if (j < len && a[j] < a[j+1])
            j++;
        if (a[k] >= a[j])
            break;
        exch(a[k], a[j]);
        k = j;
    }
}
void heapsort(int a[], int left, int right)
{
    int k, len = right-left+1;
    for(k = len/2; k >= 1; k--)
        fixDown(&a[left-1], k, len);
    while(len > 1){
        exch(a[left], a[left-1+len]);
    fixDown(&a[left-1], 1, --len); }
}*/
void fixDown(int *a, int k, int len)
{
    int j;
    while (2*k+1 <= len-1){
        j = 2*k+1;
        if(j < len-1 && a[j] < a[j+1])
            j++;
        if(a[k] >= a[j])
            break;
        exch(a[k], a[j]);
        k = j;
    }

}
void heapsort(int *a, int left, int right)
{
    int k, len = right-left+1;
    for(k = len/2-1; k >= 0; k--)
        fixDown(a, k, len);
    while(len > 1){
        exch(a[left], a[left-1+len]);
        fixDown(a, 0, --len);
    }
}

void mergeAB(int *e, int *a, int alen, int *b, int blen)
{
    int i = 0, j = 0, k = 0;
    for( ; k < alen+blen; k++){
        if(i == alen){
            e[k] = b[j++];
            continue;
        }
        if(j == blen){
            e[k] = a[i++];
            continue;
        }
        e[k] = (a[i] < b[j] ? a[i++] : b[j++]);
    }
}
int aux[100];
void merge(int *src, int left, int mid, int right)
{
    int i, j, k;
    for(i = mid+1; i > left; i--)
        aux[i-1] = src[i-1];
    for(j = mid; j < right; j++)
        aux[right+mid-j] = src[j+1];
    for(k = left; k <= right; k++)
        src[k] = (aux[i] < aux[j] ? aux[i++] : aux[j--]);
}
void merge_sort(int *src, int left, int right)
{
    if(right <= left)
        return;
    int mid = (left+right)/2;
    merge_sort(src, left, mid);
    merge_sort(src, mid+1, right);
    merge(src, left, mid, right);
}


int main(void)
{
    int t[] = {5, 3, 1, 6, 7};
    heapsort(t, 0, sizeof(t)/sizeof(t[0])-1);
    int i;
    for(i = 0; i < sizeof(t)/sizeof(t[0]); i++)
        printf("%d ", t[i]);
    printf("\n");
    //int a[] = {1, 3, 5, 7, 9};
    //int b[] = {2, 4, 6, 8, 10};

    //mergeAB(e, a, 5, b, 5);
    //printf("%d\n", digit(13, 3));
    //int e[] = {13, 9};
    //merge_sort(e, 0, 9);
    //lsdradix_sort(e, 0, 1);

    return 0;
}





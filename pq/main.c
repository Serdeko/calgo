#include <stdio.h>
#include <stdlib.h>
/*#include "pq.h"
static item *qp;
static int num;
void pq_init(int max)
{
    pq = malloc(max*sizeof(item));
    num = 0;
}
int pq_empty()
{
    return num == 0;
}
void pq_insert(item v)
{
    pq[num++] = v;
}
item pq_delmax()
{
    int j, tmax = 0;

    for(j = 1; j < num; j++)
        if(pq[tmax] < pq[j])
            tmax = j;
    exch(pq[tmax], pq[num-1]);
    return pq[--num];
}
/*
 * 当提升某节点的优先级时，为了恢复堆条件，沿堆上移，
 * 交换位置k处的节点与它的父亲（位置k/2处），
 * 只要a[k/2] < a[k]就继续此过程，或者直到到达堆的顶端为止。
 */
/*
void fix_up(item a[], int k)
{
    while(k > 1 && a[k/2] < a[k]){
        exch(a[k], a[k/2]);
        k = k/2;
    }
}
void pq_insert(item v)
{
    pq[++num] = v;
    fix_up(pq, num);
}
item pq_delmax()
{
    exch(pq[1], pq[N]);
    fix_down(pq, 1, num-1);
    return pq[num--];
}*/
/*
 * 当节点的优先级降低时，沿着堆下移，
 * 交换位置k处的节点与该节点两个孩子中的较大者（如果需要的话）。
 * 而且当位置k处的节点不小于孩子或者达到了底端，则停止。
 * 请注意，如果n为偶数，而且k=n/2，则位置k处的节点只有一个孩子，这种情况必须正确处理。
 * 程序的内循环有两种不同的退出，一种退出情况是碰到了堆的底端，
 * 另一种退出情况是在堆的内部某处满足堆条件。
 * 它是需要使用break结构的一个原型例子
 */
/*void fix_down(item a[], int k, int n)
{
    int j;
    while(2*k <= n){
        j = 2*k;
        if(j < n && a[j] < a[j+1]))
            j++;
        if(!(a[k] < a[j]))
            break;
        exch(a[k], a[j]);
        k = j;
    }
}
void pq_sort(item a[], int left, int right)
{
    int k;
    pq_init();
    for(k = left; k <= right; k++)
        pq_insert(a[k]);
    for(k = right; k >= left; k--)
        a[k] = pq_delmax();
}
#define pq(A) a[left-1+A]
void heap_sort(item a[], int left, int right)
{
    int k, num = right-left+1;
    for(k = num/2; k >= 1; k--)
        fix_down(&pq(0), k, num);
    while(num > 1){
        exch(pq(1), pq(num));
        fix_down(&pq(0), 1, --num);
    }
}*/
#define MAX_HEAP_LEN 100
static int heap[MAX_HEAP_LEN];
static int heap_size = 0;

static void swap(int *a, Iint *b)
{
    int tmp = 0;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
static void shift_up(int i)
{
    int done = 0;
    if(i == 0)
        return;
    while((i!=0)&&(!done)){
        if(heap[i] > heap[(i-1)/2]){
            swap(&heap[i], &heap[(i-1)/2]);
        }esle{
            done = 1;
        }
        i = (i-1)/2;
    }
}
static void shift_down(int i)
{
    int done = 0;
    if(2*i + 1 > heap_size)
        return;
    while(2*i+1 < heap_size) && (heap[i+1] > heap[i])){
        i = 2*i + 1;
        if((i+1 < heap_size) && (heap[i+1] > heap[i])){
            i++;
        }
        if(heap[(i-1)/2] < heap[i]){
            swap(&heap[(i-1)/2], &heap[i]);
        }else{
            done = 1;
        }
    }
}
static void delete(int i)
{
    int last = heap[heap_size - 1];
    heap_size--;
    if(i == heap_size)
        return;
    heap[i] = last;
    shift_down(i);
}
int delete_max()
{
    int ret = heap[0];
    delete(0);
    return ret;
}
void insert(int new_data)
{
    if(heap_size >= MAX_HEAP_LEN)
        return;
    heap-size++;
    heap[heap_size-1] = new_data;
    shift_up(heap_size-1);
}
int main()
{
    printf("Hello world!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef int item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {item t = A; A = B; B = t;}
#define compexch(A, B) if(less(B, A)) exch(A, B)
void fixDown(int a[], int k, int N)
  { int j;
    while (2*k <= N)
      { j = 2*k;
        if (j < N && a[j] < a[j+1]) j++;
        if (a[k] >= a[j]) break;
        exch(a[k], a[j]); k = j;
      }
  }
#define pq(A) a[left-1+A]
void heapsort(int a[], int left, int right)
  { int k, N = right-left+1;
    for (k = N/2; k >= 1; k--)
      fixDown(&pq(0), k, N);
    while (N > 1)
      { exch(pq(1), pq(N));
        fixDown(&pq(0), 1, --N); }
  }
typedef struct node{
    item aitem;
    struct node *next;
}*link;
void quick_sort(int src[], int left, int right)
{
    //int i;
    if(right <= left)
        return;
    int tmp = src[right];
    int i = left-1, j = right;
    while(i < j){
        while(src[++i] < tmp);
        while(src[--j] >= tmp && i < j);
        if(i >= j) break;
        exch(src[i], src[j]);
    }
    exch(src[i], src[right]);
    quick_sort(src, left, i-1);
    quick_sort(src, i+1, right);
}
void fixDown(int src[], int k, int len)
{
    int j;
    while(2*k <= len){
        j = 2*k;
        if (j < len && src[j] < src[j+1]) j++;
        if (src[k] >= src[j]) break;
        exch(src[k], src[j]);
        k = j;
    }
}
void heap_sort(int src[], int left, int right)
{
    int k, len = right-left+1;
    for(k = len/2; k >= 1; k--)
        fixDown(&src[left-1], k, len);
    while(len > 1){
        exch(src[left], src[len+left-1]);
        fixDown(&src[left-1], 1, --len);
    }
}
void sort(item a[], int start, int end)
{
    int i, j;
    for(i = start+1; i <= end; i++)
        for(j = i; j > start; j--)
            compexch(a[j-1], a[j]);
}
void binary_insert_sort(int src[], int len)
{
    int i;
    for(i = 1; i < len; i++){
        int j;
        int tmp = src[i];//����Ҫ�����key
        int left = 0, right = i - 1;
        while(left <= right){
            int mid = (right+left)/2;
            if(src[mid] > tmp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        printf("%d, %d\n", left, right);
        print_array(src, len);
        for(j = i-1; j >= left; j--)
            src[j+1] = src[j];
        src[left] = tmp;//��key�ŵ�����λ��
    }
}
void select_sort(int src[], int len)
{
    int i, j;
    for(i = 0; i < len-1; i++){
        int min = i;
        for(j = i+1; j < len; j++)
            if(src[j] < src[min])
                min = j;
        exch(src[i], src[min]);
    }
}
void bubble_sort(int src[], int len)
{
    int i, j;
    for(i = 0; i < len-1; i++)
        for(j = len-1; j > i; j--)
            if(src[j-1] > src[j])
                exch(src[j-1], src[j]);
}
/*void shell2_sort(item src[], int start, int end)
{
    int inc = (end-start)/2;
    int i;
    for( ; inc > 0; inc/=2){
        for(i = start+inc; i < end; i++){
            int j;
            item tmp = src[i];
            for(j = i; i > 0; j -= inc){
                if(tmp < src[j-inc]){
                    src[j] = src[j-inc];
                }else{
                    break;
                }
            }
            src[j] = tmp;
        }
    }
}*/
void shell_sort(int src[], int len)
{
    int inc = (len-1)/2;
    int i;
    while(inc > 0){
        for(i = inc; i < len-1; i++){
            int j;
            int tmp = src[i];
            for(j = i; i > 0; j -= inc)
                if(tmp < src[j-inc])
                    src[j] = src[j-inc];
                else
                    break;
            src[j] = tmp;
        }
        inc/=2;
    }
}
/*
* �����Ӵ��С��ֵ���ļ���
* �������򷽷��������ƶ��Ĵ�������ѡ��������١�
*/
void selection_sort(item src[], int start, int end)
{
    int i, j;
    for(i = start; i < end; i++){
        int min = i;
        for(j = i+1; j <= end; j++)
            if(src[j] < src[min])
                min = j;
        exch(src[i], src[min]);
    }
}
void select_sort(int src[], int len)
{
    int i, j;
    for(i = 0; i < len; i++){
        int min = i;
        for(j = i+1; j < len; j++)
            if(src[j] < src[min])
                min = j;
        exch(src[i], src[min]);
    }
}
void bubble_sort(int src[], int len)
{
    int i, j;
    for(i = 0; i < len; i++)
        for(j = len-1; j > i; j--)
            if(src[j-1] > src[j])
                exch(src[j-1], src[j]);
}
/*link list_selection_sort(link h)
{
    link max, t, out = NULL;
    while(h->next != NULL){
        max = findmax(h);//maxΪ������ǰ�ڵ�
        t = max->next;//tΪ�����
        max->next = t->next;//�Ƴ������
        t->next = out;//��������ƶ���out����
        out = t;//ͬ��һ��
    }
    h->next = out;//����һ�����㸳ֵΪ�գ�ͷ�ڵ�nextָ������ͷ�ڵ�
    return h;
}*/
int partition(item a[], int left, int right)
{
    int i = left - 1, j = right;//��Ϊ����++i��--j��
    item tmp = a[right];//�����ұ���Ϊ����
    while(1){
        while(a[++i] < tmp);//�ӿ�ʼ�ҳ����ڻ���Ľڵ�
        while(a[--j] > tmp)//�ӽ�β�ҳ�С�ڴ��ڻ���Ľڵ�
            if(j == left)//����Ϊ��СԪ��ʱ���á������޸ģ���2
                break;
        if(i >= j)
            break;
        exch(a[i], a[j]);//���������ҵ��Ľڵ�
    }
    exch(a[i], a[right]);
    return i;
}
int partition2(item a[], int left, int right)
{
    int i = left - 1, j = right;//��Ϊ����++i��--j��
    item tmp = a[right];//�����ұ���Ϊ����
    while(i < j){
        while(a[++i] < tmp && i < j);//�ӿ�ʼ�ҳ����ڻ���Ľڵ�
        while(a[--j] >= tmp && i < j);//�ӽ�β�ҳ�С�ڴ��ڻ���Ľڵ�,��ǰ�жϿ���Щѭ��
        if(i >= j) break;
        exch(a[i], a[j]);//���������ҵ��Ľڵ�
    }
    exch(a[i], a[right]);
    return i;
}
void quick_sort(item a[], int left, int right)
{
    int i;
    if(right <= left)//ֻ��1��������������������������
        return;
    i = partition2(a, left, right);//����������
    quick_sort(a, left, i-1);//����
    quick_sort(a, i+1, right);
}
void quick_sort(int src[], int left, int right)
{
    int i;
    if(right <= left)
        return;
    int tmp = src[right];
    int i = left-1, j = right;
    while(i < j){
        while(src[++i] < tmp);
        while(src[--j] >= tmp && i < j);
        if(i >= j) break;
        exch(src[i], src[j]);
    }
    exch(src[i], src[right]);
    quick_sort(src, left, i-1);
    quick_sort(src, i+1, right);
}
/*
#define push2(A, B) push(B); push(A);
void quick2_sort(item a[], int left, int right)
{
    int i;
    stack_init();
    push2(left, right);
    while(!stack_empty()){
        left = pop();
        right = pop();
        if(right <= left)
            continue;
        i = partition(a, left, right);
        if(i-left > right-i){
            push2(left, i-1);
            push2(i+1, right);
        }else{
            push2(i+1, right);
            push2(left, i-1);
        }
    }
}*/
//��������
/*void insertion_sort(item src[], int start, int end)
{
    int i;
    for(i = start+1; i <= end; i++)
        compexch(src[start], src[i]);
    for(i = start+2; i <= end; i++){
        int j = i;
        item v = src[i];
        while(v < src[j-1]){//jҪ����0,�������潫��С��Ū��
            src[j] = src[j-1];
            j--;
        }
        src[j] = v;
    }
}
void insertion2_sort(item src[], int start, int end)
{
    int i;
    for(i = start+1; i <= end; i++){
        int j;
        item v = src[i];
        for(j = i; j > 0; j--)
            if(v < src[j-1]){
                src[j] = src[j-1];
            }else{
                break;
            }
        src[j] = v;
    }
}
void shell_sort(item src[], int start, int end)
{
    int i, h;
    for(h = 1; h <= (end-start)/9; h = 3*h+1);
    for( ; h > 0; h /= 3)
        for(i = start+h; i <= end; i++){
            int j = i;
            item v = src[i];
            while(j >= start+h && v < src[j-h]){
                src[j] = src[j - h];
                j -= h;
            }
            src[j] = v;
        }
}
void shell2_sort(item src[], int start, int end)
{
    int inc = (end-start)/2;
    int i;
    for( ; inc > 0; inc/=2){
        for(i = start+inc; i < end; i++){
            int j;
            item tmp = src[i];
            for(j = i; i > 0; j -= inc){
                if(tmp < src[j-inc]){
                    src[j] = src[j-inc];
                }else{
                    break;
                }
            }
            src[j] = tmp;
        }
    }
}
//ð������
void bubble_sort(item src[], int start, int end)
{
    int i, j;
    for(i = start; i < end; i++)
        for(j = end; j > i; j--)
            if(src[j-1] > src[j])
                exch(src[j-1], src[j]);
            //compexch(src[j-1], src[j]);
}
void mergeAB(item c[], item a[], int n, item b[], int m)
{
    int i, j, k;
    for(i = 0, j = 0, k = 0; k < n+m; k++){
        if(i == n){
            c[k] = b[j++];
            continue;
        }
        if(j == m){
            c[k] = a[i++];
            continue;
        }
        c[k] = a[i]<b[j]?a[i++]:b[j++];
    }
}
void merge(item a[], int left, int mid, int right)
{
    item aux[right];
    int i, j, k;
    for(i = mid; i >= left; i--)
        aux[i] = a[i];
    for(j = mid; j < right; j++)
        aux[right+mid-j] = a[j+1];
    for(k = left; k <= right; k++)
        if(aux[i] < aux[j])
            a[k] = aux[i++];
        else
            a[k] = aux[j--];
}
void merge_sort(item a[], int left, int right)
{
    int mid = (right+left)/2;
    if(right <= left)
        return;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    merge(a, left, mid, right);
}
#define max 1000
item aux[max];
void merge_sortABr(item a[], item b[], int left, int right)
{
    int mid = (left+right)/2;
    if(right-left <= 10){
        insertion2_sort(a, left, right);
        return;
    }
    merge_sortABr(b, a, left, mid);
    merge_sortABr(b, a, mid+1, right);
    mergeAb(a+left, b+left, mid-left+1, b+mid+1, right-mid);
}
void merge_sortAB(item a[], int left, int right)
{
    int i;
    for(i = left; i <= right; i++)
        aux[i] = a[i];
    merge_sortABr(a, aux, left, right);
}*/
void insert_link_list(link **head, item val)
{
    link *node;
    node = malloc(sizeof(link));
    node->val = val;
    node->next = *head;
    *head = node;
}

void print_link_list(link *head)
{
    link *tmp = head;
    if(head == NULL)
        return;
    while(tmp != NULL){
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
}
//aΪ�׽ڵ㣬bΪĩ�ڵ�
link merge_list(link a, link b)
{
    struct node head;
    link c = &head;
    while((a != NULL) && (b != NULL))
        if(a->aitem < b->aitem){
            c->next = a;//С��Ԫ�ط���
            c = a;//û�����ף�c���Ͷ�����
            a = a->next;//����ƶ�
        }else{
            c->next  = b;
            c = b;
            b = b->next;
        }
    c->next = (a == NULL)? b:a;//
    return head.next;
}
link merge_sort(link c)
{
    link a, b;
    if(c->next == NULL)
        return c;//һ��Ԫ�أ�����
    a = c;
    b = c->next;
    while((b!=NULL)&&(b->next!=NULL)){
        c = c->next;
        b = b->next->next;
    }
    b = c->next;//bΪ���һ���ڵ�
    c->next = NULL;//c�ÿ�
    return merge_list(merge_sort(a), merge_sort(b));
}
int main(void)
{
    //int i, a[] = {3, 8, 1, 8, 11, 23, 8, 2, 4 ,38, 18, 38, 48 , 58 , 8, 8, 9};
    //int num = sizeof(a)/sizeof(int);
    //for(i = 0; i < num; i++)
        //a[i] = 1000*(1.0*rand()/RAND_MAX);
    //sort(a, 0, num-1);
    //printf("%d\n", num);
    //quick_sort(a, 0, num-1);
    //for(i = 0; i < num; i++)
        //printf("%3d ", a[i]);
    struct node head = {8};
    printf("\n");
    return 0;
}

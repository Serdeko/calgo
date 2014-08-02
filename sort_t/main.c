#include <stdio.h>
#define exch(a, b) {int t = a;a = b;b = t;}//交换a，b
void print_array(int src[], int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("%d ", src[i]);
    printf("\n");
}
void insert_sort(int src[], int len)
{
    int i;
    for(i = 1; i < len; i++){
        int j;
        int tmp = src[i];//保存要排序的key
        for(j = i-1; j >= 0; j--){//和已经排序的序列比较
            if(src[j] > tmp)//如果值比key大，值往后移动一位
                src[j+1] = src[j];
            else
                 break;
        }
        src[j+1] = tmp;//将key放到合适位置
        print_array(src, len);
    }
}
void binary_insert_sort(int src[], int len)
{
    int i;
    for(i = 1; i < len; i++){
        int j;
        int tmp = src[i];//保存要排序的key
        //找到比key大第一个数或者比key小的最后一个数
        //left是第一个比key大的数的下标
        int left = 0, right = i-1;
        while(left<=right){
            int mid = (right+left)/2;
            if(src[mid] > tmp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        //下标left至下标i-1是比key(src[i])大的数
        for(j = i-1; j >= left; j--)
            src[j+1] = src[j];
        src[left] = tmp;
        //src[j+1] = tmp;//将key放到合适位置
        print_array(src, len);
    }
}
#define exch(a, b) {int t = a;a = b;b = t;}
void bubble_sort(int src[], int len)
{
    int i, j;
    //循环len-2
    for(j = 0; j < len-1; j++){
        //每趟排好，排好值不参与后续排序
        for(i=len-1; i > j; i--){
            if(src[i-1] > src[i]){
                int t = src[i-1];
                src[i-1] = src[i];
                src[i] = t;
            }
        }
    }
}
void select_sort(int src[], int len)
{
    int j;
    for(j = 0; j < len-1; j++){
        int i, min = j, tmp = src[j];
        for(i = j+1; i < len; i++){
            if(src[i] < tmp){
                tmp = src[i];
                min = i;
            }
        }
        if(min != j)
            exch(src[min], src[j]);
    }
}
void shell_sort(int src[], int len)
{
    int inc, i, j;
    //步长循环
    for(inc = len/2; inc >= 1; inc /= 2){
        //从下标inc开始比较
        for(i = inc; i < len; i++){
            //从下标inc至i和前面间隔inc的数据比较
            for(j = i; j >= inc; j-=inc){
                if(src[j-inc] > src[j]){
                    exch(src[j-inc], src[j]);
                }
            }
        }
    }
}

void quick_sort(int src[], int left, int right)
{
    if(right <= left)
        return;
    //取下标最大为value
    int value = src[right];
    //根据value划分2块，左边比value小，右边比value大
    //下标是left至right-1,但为了while循环简洁
    //使用此方法
    int i = left-1, j = right;
    while(i < j){
        while(src[++i] < value);
        while(src[--j] >= value && i < j);
        if(i >= j)
            break;
        exch(src[i], src[j]);
    }
    //交换value与相交那个值
    exch(src[i], src[right]);
    //将左块递归划分
    quick_sort(src, left, i-1);
    //将右块递归划分
    quick_sort(src, i+1, right);
}
#define exch(a, b) {int t = a;a = b;b = t;}//交换a，b
void fix_down(int *s, int k, int len)
{
    int j;
    while(2*k+1 < len){
        j = 2*k + 1;
        if(j < len-1 && s[j] < s[j+1])
            j++;
        if(s[k] > s[j])
            break;
        exch(s[k], s[j]);
        k = j;
    }
}
void heap_sort(int *src, int left, int right)
{
    int i;
    int len = right-left+1;
    for(i = len/2 - 1; i >= 0 ; i--)
        fix_down(src, i, len);
    while(len > 1){
        exch(src[0], src[len-1]);
        fix_down(src, 0, --len);
    }
}

void mergeAB(int *c, int *a, int alen, int *b, int blen)
{
    int i = 0, j = 0, k = 0;
    for(k = 0; k < alen+blen; k++){
        if(i > alen-1){
            c[k] = b[j++];
            continue;
        }
        if(j > blen-1){
            c[k] = a[i++];
            continue;
        }
        c[k] = (a[i] > b[j] ? b[j++] : a[i++]);
    }
}
int tmp[100];
void merge(int *src, int left, int mid, int right)
{
    int i, j, k;
    for(i = mid+1; i > left; i--)
        tmp[i-1] = src[i-1];
    for(j = mid; j < right; j++)
        tmp[right+mid-j] = src[j+1];
    for(k = left; k <= right; k++)
        src[k] = (tmp[i] > tmp[j] ? tmp[j--] : tmp[i++]);
}
void merge_sort(int *src, int left, int right)
{
    if(left >= right)
        return;
    int mid = (right+left)/2;
    merge_sort(src, left, mid);
    merge_sort(src, mid+1, right);
    merge(src, left, mid, right);
    print_array(tmp, 9);
}
int main()
{
    int s[10] = {3, 4, 9, 21, 8, 2, 5, 7, 6, 11};
    //int b[] = {2, 4, 6, 7};
    select_sort(s, 10);
    int i;
    for(i = 0; i < sizeof(s)/sizeof(s[0]); i++)
        printf("%d ", s[i]);
    printf("\n");

    /*merge_sort(a, 0, sizeof(a)/sizeof(a[0])-1);
    int i;
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("%d ", a[i]);
    */
    /*int s[] = {8, 4, 3, 2, 5};
    heap_sort(s, 0, sizeof(s)/sizeof(s[0])-1);

    */

    return 0;
}

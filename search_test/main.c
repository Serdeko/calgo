#include <stdio.h>
#include <string.h>
int search1(int src[], int len)
{
    int i, tmp = src[0];

    for(i = 1; i < len; i++)
        if(tmp > src[i])
            tmp = src[i];

    return tmp;
}
//src[]是从小到大排序
/*int binary_search(int src[], int left, int right, int key)
{
    //int left = 0, right = len - 1;//最右边下标

    while(left <= right){
        int mid = (right+left)/2;//下标计算
        if(src[mid] == key)
            return mid;
        else if(src[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int binary_search2(int src[],
                   int left, int right, int key)
{
    int mid = (right+left)/2;

    if(left > right)
        return -1;
    if(src[mid] == key){
        return mid;
    }else if(src[mid] > key){
        return binary_search2(src, left, mid-1, key);
    }else{
        return binary_search2(src, mid+1, right, key);
    }
}

int d[10][2];
void build_hash(int t)
{
    int i = t%10;
    int j;
    for(j = 0; j < 2; j++)
        if(d[i][j] == -1){
            d[i][j] = t;
            break;
        }
}
int search_hash(int);

int search_hash(int t)
{
    int i = t%10;
    int j;
    for(j = 0; j < 2; j++)
        if(d[i][j] == t){
            return 1;
        }
    return 0;
}
void init_hash()
{
    int i, j;
    for(i = 0; i < 10; i++)
        for(j = 0; j < 2; j++)
            d[i][j] = -1;
}

void swap(int a, int b)//a = 3, b = 5;
{
    printf("1f %d, %d\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("2f %d, %d\n", a, b);
}
void swap2(int *a, int *b)
{
    printf("1f %d, %d\n", *a, *b);
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("2f %d, %d\n", *a, *b);
}
*/
/*
void preKmp(char *x, int m, int kmpNext[]) {
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}
void KMP(char *x, int m, char *y, int n) {
   int i, j, kmpNext[m];


   preKmp(x, m, kmpNext);

   for(i = 0; i < m; i++){
       printf("%d ", kmpNext[i]);
   }
   printf("\n");

   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         //OUTPUT(j - i);
         printf("%d\n", j-i);
         i = kmpNext[i];
      }
   }
}

int bf_search(char *s, char *p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    int i = 0, j = 0, k = 0;
    while(i < len_s && j < len_p){
        if(s[i+k] == p[j])
            ++k, ++j;
        else
            ++i, j = 0, k = 0;
    }
    if(j == len_p)
        return i;
    else
        return -1;
}
*/
/*
void kmpSearch(char *s, char *p)
{
    int i=0, j=0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    int kmp_next[len_p];
    kmpPreprocess(p, kmp_next);
    while(i<len_s)
    {
        while (j>=0 && s[i]!=p[j])
            j=kmp_next[j];
        i++; j++;
        if(j==len_p){
            printf("%d\n", i-j);
            j=kmp_next[j];
        }
    }
}
*/
void pre_kmp(char *p, int *kmp_next)
{
    int len_p = strlen(p);
    int i = 0, j = -1;

    kmp_next[0] = -1;
    while(i < len_p){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            if(p[i] != p[j])
                kmp_next[i] = j;
            else
                kmp_next[i] = kmp_next[j];
        }else
            j = kmp_next[j];
    }
}

int kmp_search(char *s, char *p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    int kmp_next[len_p];
    pre_kmp(p, kmp_next);
    int i = 0, j = 0;
    while(i < len_s && j < len_p){
        if(j == -1 || s[i] == p[j])
            ++i, ++j;
        else
            j = kmp_next[j];
    }
    if(j >= len_p)
        return i-len_p;
    else
        return -1;
}
#define len(x) (sizeof(x)/sizeof(x[0]) - 1)
/*
void kmpPreprocess(char *p, int *kmp_next)
{
    int i=0, j=-1;
    kmp_next[i]=j;
    int len_p = strlen(p);
    while (i<len_p){
        while(j>=0 && p[i]!=p[j])
            j=kmp_next[j];
        i++; j++;
        kmp_next[i]=j;
    }
}

int kmpSearch(char *s, char *p)
{
    int i=0, j=0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    int kmp_next[len_p];
    kmpPreprocess(p, kmp_next);
    while(i<len_s)
    {
        while (j>=0 && s[i]!=p[j])
            j=kmp_next[j];
        i++; j++;
        if(j==len_p)
            return i-j;
    }
    return -1;
}
*/
void kmpPreprocess(char *p, int *kmp_next)
{
    int i=0, j=-1;
    kmp_next[i]=j;
    int len_p = strlen(p);
    while (i<len_p){
        while(j>=0 && p[i]!=p[j])
            j=kmp_next[j];
        i++; j++;
        kmp_next[i]=j;
    }
}
int kmpSearch(char *s, char *p)
{
    int i=0, j=0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    int kmp_next[len_p];
    kmpPreprocess(p, kmp_next);
    while(i<len_s)
    {
        while(j >= 0 && s[i]!=p[j])
            j=kmp_next[j];
        i++; j++;
        if(j==len_p)
            return i-j;
    }
    return -1;
}
int bf_search(char *s, char *p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);
    int i = 0, j = 0, k = 0;
    while(i < len_s && j < len_p){
        if(s[i+k] == p[j])
            ++k, ++j;
        else
            ++i, j = 0, k = 0;
    }
    if(j == len_p)
        return i;
    else
        return -1;
}
int bfSearch(char *s, char *p)
{
    int i=0, j=0, k=0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    while(i<len_s)
    {
        while(s[i+k]!=p[j])
            ++i, j = 0, k = 0;
        k++; j++;
        if(j==len_p)
            return i;
    }
    return -1;
}
int main()
{
    char s[] = "ababacbac";
    char p[] = "aaaaaaaaa";
    //printf("%d\n", bf_search(s, p));
    printf("%d\n", kmpSearch(s, p));
    //printf("%d\n", bf_search(s, p));
    int kmpnext[len(p)];
    //kmpPreprocess(p, kmpnext);
    kmpPreprocess(p, kmpnext);
    int i;
    for(i = 0; i < len(p); i++)
        printf("%d ", kmpnext[i]);
    printf("\n");
    return 0;
}







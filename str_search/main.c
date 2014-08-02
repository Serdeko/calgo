#include <stdio.h>
#include <string.h>
//s---源字符串  p----需要匹配的字符串
int bf_search(char *s, char *p)
{
    //i是s的下标，j是p的下标，
    //k是p已经比较的次数
    int i = 0, j = 0, k = 0;
    int slen = strlen(s);
    int plen = strlen(p);
    while(i < slen){
        while(s[i+k] != p[j])
            i++, j = 0, k = 0;
        j++, k++;
        if(j == plen)
            return i;
    }
    return -1;
}
void kmp_pre(char *p, int *kmp_next)
{
    int i = 0, j = -1;
    int plen = strlen(p);
    kmp_next[0] = -1;
    while(i < plen){
        while(j >=0 && p[i] != p[j])
            j = kmp_next[j];
        i++, j++;
        kmp_next[i] = j;
    }
}
int kmp_search(char *s, char *p)
{
    int i = 0, j = 0;
    int slen = strlen(s);
    int plen = strlen(p);
    int kmp_next[plen];
    kmp_pre(p, kmp_next);
    int x;
    for(x = 0; x < plen; x++)
        printf("%d ", kmp_next[x]);
    printf("\n");
    while(i < slen){
        printf("a|%d, %d, %c, %c\n", i, j, s[i], p[j]);
        while(j >= 0 && s[i] != p[j])
            j = kmp_next[j];
        printf("b|%d, %d\n", i, j);
        i++, j++;
        if(j == plen)
            return i-j;
    }
    return -1;
}
int main()
{
    char s[] = "abcgabcdabgabcdabcdabd";
    char p[] = "abcdabd";
    printf("%d\n", kmp_search(s, p));
    return 0;
}

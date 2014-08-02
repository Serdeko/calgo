#include <stdio.h>
#include <stdlib.h>
//拷贝src到dest
//拷贝至'\0'（含）结束
//返回dest的地址
char *mstrcpy(char dest[], const char src[])
{
    printf("%d\n", sizeof(src));
    //判断参数传入是否正确
    if(dest == NULL || src == NULL)
        return NULL;
    //拷贝src到dest直到'\0'(含)
    int i;
    for(i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return dest;
}
char *mstrcpy2(char *dest, const char *src)
{
    //判断参数传入是否正确
    if(dest == NULL || src == NULL)
        return NULL;
    //拷贝src到dest直到'\0'(含)
    char *tmp = dest;
    while((*(dest++) = *(src++)) != '\0');
    return tmp;
}
//size_t  无符号整数，库文件定义的一个类型
//unsigned int
//拷贝src到dest一共n个字符，或者直到src结束'\0'
//src结束时要拷贝至'\0'（含）
//返回dest的地址
char *mstrncpy(char *dest, const char *src, size_t n)
{
    if(dest == NULL || src == NULL)
        return NULL;
    //拷贝src到dest直到'\0'(含)
    char *tmp = dest;
    //拷贝src到dest直到'\0'(含)，若src未结束则拷贝n个字符
    while(n--)
        if((*(dest++) = *(src++)) == '\0')
            break;

    return tmp;
}
//strncpy功能一样的，不管结束符'\0'
//拷贝src至dest一共n个字符
void *m_memcpy(void *dest, const void *src, size_t n)
{
    if(dest == NULL || src == NULL)
        return NULL;
    //拷贝src至dest一共n个字符
    //char *tmp = (char *)dest;
    while(n--)
        *((char *)dest+n) = *((char *)src+n);
    return dest;
}
int main()
{
    /*char s[] = "abcde";
    char *p, t[6];
    p = m_memcpy(t, s, 6);
    printf("%s\n", p);*/
    int i = 5, *p;
    void *gp;
    gp = &i;
    p = gp;
    printf("%d\n", *p);
    return 0;
}












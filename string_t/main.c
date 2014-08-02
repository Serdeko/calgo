#include <stdio.h>
#include <stdlib.h>
//����src��dest
//������'\0'����������
//����dest�ĵ�ַ
char *mstrcpy(char dest[], const char src[])
{
    printf("%d\n", sizeof(src));
    //�жϲ��������Ƿ���ȷ
    if(dest == NULL || src == NULL)
        return NULL;
    //����src��destֱ��'\0'(��)
    int i;
    for(i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return dest;
}
char *mstrcpy2(char *dest, const char *src)
{
    //�жϲ��������Ƿ���ȷ
    if(dest == NULL || src == NULL)
        return NULL;
    //����src��destֱ��'\0'(��)
    char *tmp = dest;
    while((*(dest++) = *(src++)) != '\0');
    return tmp;
}
//size_t  �޷������������ļ������һ������
//unsigned int
//����src��destһ��n���ַ�������ֱ��src����'\0'
//src����ʱҪ������'\0'������
//����dest�ĵ�ַ
char *mstrncpy(char *dest, const char *src, size_t n)
{
    if(dest == NULL || src == NULL)
        return NULL;
    //����src��destֱ��'\0'(��)
    char *tmp = dest;
    //����src��destֱ��'\0'(��)����srcδ�����򿽱�n���ַ�
    while(n--)
        if((*(dest++) = *(src++)) == '\0')
            break;

    return tmp;
}
//strncpy����һ���ģ����ܽ�����'\0'
//����src��destһ��n���ַ�
void *m_memcpy(void *dest, const void *src, size_t n)
{
    if(dest == NULL || src == NULL)
        return NULL;
    //����src��destһ��n���ַ�
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












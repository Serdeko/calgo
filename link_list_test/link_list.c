#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

link *init_link(void)
{
    return NULL;
}
//����aitem���������������µĵ�����ͷ���
link *insert_link(link *head,dataType aitem)
{
    link *p=malloc(sizeof(*p));
    p->item=aitem;
    p->next=head;
    return p;
}
void insert_link_d(link **head,dataType aitem)
{
    link *p=malloc(sizeof(*p));
    p->item=aitem;
    p->next=*head;
    *head = p;//*a = 5;  head = p;
}
//��������ĵ�����
link *insert_sort_link(link *head,dataType aitem)
{
    link *p=malloc(sizeof(*p));
    p->item=aitem;
    if(head==NULL)
    {
        p->next=NULL;
        return p;
    }
    link  *curr=head,*pre=head;

    while(curr!=NULL)
    {
        if(curr->item>=aitem)
        {
            p->next=curr;
            if(curr==head&&pre==head)
                return p;
            pre->next=p;
            return head;
        }
        pre=curr;
        curr=curr->next;
    }
    //δ�ҵ���aitem��Ľڵ�
    p->next=NULL;
    pre->next=p;
    return head;
}
//ɾ��aitem�Ľڵ�
link *delete_one(link *head,dataType aitem)
{
    if(head == NULL)
        return NULL;
    //Pre��Ҫɾ���ڵ��ǰһ���ڵ�
    link *pre=NULL,*p=head;

    //�ҵ�Ҫɾ���Ľڵ�
    while (head!=NULL&&head->item!=aitem)
    {
        pre=head;
        head=head->next;
    }
    //ɾ���ڵ�
    if(pre!=NULL&&head->item==aitem)
    {
        pre->next=head->next;
    }else{
        p = p->next;
    }
    free(head);
    head=NULL;
    return p;
}
//ɾ������aitem�Ľڵ�
link *delete_link(link *head,dataType aitem)
{
    link *pre=head,*p=head;
    //�ҵ�Ҫɾ���Ľڵ�
    while (head!=NULL){
        //ɾ���ڵ�
        if(head->item>aitem){
            link *tmp=head;
            if (p==head)
                p=head->next;
            else
                pre->next=head->next;
            head=head->next;
            free(tmp);
            tmp=NULL;
        }else{
           pre=head;
           head=head->next;
        }
    }
    return p;
}
link *delete_link2(link *head,dataType aitem)
{
    link *pre = NULL, *curr = head;
    //�ҵ�Ҫɾ���Ľڵ�
    while (curr){
        //ɾ���ڵ�
        link *next = curr->next;
        if(curr->item > aitem){
            if(pre)//pre!=NULL
                pre->next = next;
            else
                head = next;
            free(curr);
            curr = NULL;
        }else
           pre = curr;
        curr = next;
    }
    return head;
}
link *link_reverse(link *head)
{
    //t�Ǳ����ʣ��ԭ������ͷָ��
    //y�����ڷ�ת�Ľڵ�ָ��
    //r���Ѿ���ת�õĵ�����ͷָ��
    link *t,*y=head,*r=NULL;
    while(y!=NULL)
    {
        //��תy��tָ��y����һ���ڵ�ָ��
        t=y->next;
        //���Ѿ���ת�õĵ�����ָ�븳ֵ��y��next
        y->next=r;
        //y�Ѿ���ת�ø�ֵ��r
        r=y;
        //y�Ѿ���ת�ã�������תy��һ���ڵ�
        y=t;
    }
    return  r;
}
void print_link(link *head)
{
    int i = 0;
    while(head!=NULL)
    {
        printf("%d ",head->item);
        head=head->next;
        i++;
    }
    printf("\n");
}
int count_link(link *head)
{
    int i = 0;
    while(head!=NULL)
    {
        head=head->next;
        i++;
    }
  //  printf("count:%d\n", i);
    return i;
}
int search_link_k(link *head, int k)
{
    int i;
    for(i = 0; i < k-1; i++){
        if(head != NULL)
            head = head->next;
        else
            return 0;
    }
    printf("%d\n", head->item);
    return 1;
}
int search_link_dk(link *head, int k)
{
    int i;
    link *tmp = head;
    for(i = 0; i < k-1; i++){
        if(tmp)
            tmp = tmp->next;
        else
            return 0;
    }
    printf("%d\n", tmp->item);
    while(tmp->next){
       tmp = tmp->next;
       head = head->next;
    }
    printf("%d\n", head->item);
    return 1;
}
void free_link(link *head)
{
    while(head!=NULL)
    {
        link *tmp=head;
        head=head->next;
        free(tmp);
        tmp=NULL;
    }
}

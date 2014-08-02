#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

link *init_link(void)
{
    return NULL;
}
//插入aitem至单链表，并返回新的单链表头结点
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
//插入有序的单链表
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
    //未找到比aitem大的节点
    p->next=NULL;
    pre->next=p;
    return head;
}
//删除aitem的节点
link *delete_one(link *head,dataType aitem)
{
    if(head == NULL)
        return NULL;
    //Pre是要删除节点的前一个节点
    link *pre=NULL,*p=head;

    //找到要删除的节点
    while (head!=NULL&&head->item!=aitem)
    {
        pre=head;
        head=head->next;
    }
    //删除节点
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
//删除大于aitem的节点
link *delete_link(link *head,dataType aitem)
{
    link *pre=head,*p=head;
    //找到要删除的节点
    while (head!=NULL){
        //删除节点
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
    //找到要删除的节点
    while (curr){
        //删除节点
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
    //t是保存的剩余原单链表头指针
    //y是正在反转的节点指针
    //r是已经反转好的单链表头指针
    link *t,*y=head,*r=NULL;
    while(y!=NULL)
    {
        //反转y，t指向y的下一个节点指针
        t=y->next;
        //将已经反转好的单链表指针赋值给y的next
        y->next=r;
        //y已经反转好赋值给r
        r=y;
        //y已经反转好，继续反转y下一个节点
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

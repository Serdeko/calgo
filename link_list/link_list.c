#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

link *init_link(void)
{
    return NULL;
}
//����aitem���������������µĵ�����ͷ�ڵ�
link *insert_link(link *head, dataType aitem)
{
    link *p = malloc(sizeof(*p));//link
    p->item = aitem;
    p->next = head;
    return p;
}

link *insert_sort_link(link *head, dataType aitem)
{
    link *p = malloc(sizeof(*p));
    p->item = aitem;
    //��һ�β���ڵ�
    if(head == NULL){
        p->next = NULL;
        return p;
    }
    link *curr = head, *pre = head;
    while(curr != NULL){
        if(curr->item >= aitem){
            p->next = curr;
            if(curr == head && pre == head)
                return p;
            pre->next = p;
            return head;
        }
        pre = curr;
        curr = curr->next;
    }
    //δ�ҵ���aitem��Ľڵ�
    p->next = NULL;
    pre->next = p;
    return head;
}
//ɾ��ֵΪaitem�Ľڵ�
link *delete_one(link *head, dataType aitem)
{
    //pre��Ҫɾ���ڵ��ǰһ���ڵ�
    link *pre = NULL, *p = head;
    //�ҵ�Ҫɾ���Ľڵ�
    while(head != NULL && head->item != aitem){
        pre = head;
        head = head->next;
    }
    //ɾ���ڵ�
    if(head != NULL && head->item == aitem){
        pre->next = head->next;
        free(head);
        head = NULL;
    }
    return p;
}
//ɾ������aitem�Ľڵ�
link *delete_link(link *head, dataType aitem)
{
    link *pre = NULL, *curr = head;
    //�ҵ�Ҫɾ���Ľڵ㲢ɾ��
    while(curr != NULL){
        //ɾ���ڵ�
        link *next = curr->next;
        if(curr->item > aitem){
            if(pre == NULL)
                head = next;
            else
                pre->next = next;
            free(curr);
        }else
            pre = curr;
        curr = next;
    }
    return head;
}
int search_k(link *head, int k)
{
    link *tmp = head->next, *p = head;
    int i;
    while(tmp){
        tmp = tmp->next;
        i++;
        if(i > k)
            p = p->next;
    }
    if(head == p)
        return 0;
    else{
        printf("%d\n", p->item);
        return 1;
    }
}
void delete_link_d(link **head, dataType aitem)
{
    link **curr = head;
    while(*curr){
        link *next = *curr;
        if(next->item > aitem){
            *curr = next->next;
            free(next);
        }else
            curr = &next->next;
    }
}
//��ת������
link *link_reverse(link *head)
{
    //t�Ǳ����ʣ��ԭ������ͷָ��
    //y�����ڷ�ת�Ľڵ�ָ��
    //r���Ѿ���ת�õĵ�����ͷָ��
    link *t, *y = head, *r = NULL;
    while(y != NULL){
        //��תy,tָ��y����һ���ڵ�ָ��
        t = y->next;
        //���Ѿ���ת�õĵ�����ָ�븳ֵ��y��next
        y->next = r;
        //y�Ѿ���ת�ø�ֵ��r
        r = y;
        //y�Ѿ���ת��,������תy��һ���ڵ�
        y = t;
    }
    //�����Ѿ���ת�õĵ�����ͷָ��
    return r;
}
void print_link(link *head)
{
    while(head != NULL){
        printf("%d\n", head->item);
        head = head->next;
    }
}
void free_link(link *head)
{
    while(head != NULL){
        link *tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
}

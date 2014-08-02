#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

link *init_link(void)
{
    return NULL;
}
//插入aitem至单链表，并返回新的单链表头节点
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
    //第一次插入节点
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
    //未找到比aitem大的节点
    p->next = NULL;
    pre->next = p;
    return head;
}
//删除值为aitem的节点
link *delete_one(link *head, dataType aitem)
{
    //pre是要删除节点的前一个节点
    link *pre = NULL, *p = head;
    //找到要删除的节点
    while(head != NULL && head->item != aitem){
        pre = head;
        head = head->next;
    }
    //删除节点
    if(head != NULL && head->item == aitem){
        pre->next = head->next;
        free(head);
        head = NULL;
    }
    return p;
}
//删除大于aitem的节点
link *delete_link(link *head, dataType aitem)
{
    link *pre = NULL, *curr = head;
    //找到要删除的节点并删除
    while(curr != NULL){
        //删除节点
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
//反转单链表
link *link_reverse(link *head)
{
    //t是保存的剩余原单链表头指针
    //y是正在反转的节点指针
    //r是已经反转好的单链表头指针
    link *t, *y = head, *r = NULL;
    while(y != NULL){
        //反转y,t指向y的下一个节点指针
        t = y->next;
        //将已经反转好的单链表指针赋值给y的next
        y->next = r;
        //y已经反转好赋值给r
        r = y;
        //y已经反转好,继续反转y下一个节点
        y = t;
    }
    //返回已经反转好的单链表头指针
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

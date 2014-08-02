#include <stdio.h>
#include <stdlib.h>
typedef struct link_node{
    int item;
    struct link_node *next;
}link;
link *insert_sort_link(link *head,int aitem)
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
    p->next=NULL;
    pre->next=p;
    return head;
}
int count_link(link *head)
{
    int i = 0;
    while(head!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
}
link *link_reverse_2(link *head, int k)
{
    //t是保存的剩余原单链表头指针
    //y是正在反转的节点指针
    //r是已经反转好的单链表头指针
    int n = count_link(head)-k;
    link *t,*y=head,*r=NULL, *tmp = NULL, *pre = NULL, *h = head;
    while(y!=NULL)
    {
        t=y->next;
        y->next=r;
        r=y;
        y=t;
    }
    tmp = r;
    while(n--){
        pre = tmp;
        tmp = tmp->next;
    }
    pre->next = NULL;
    h = tmp;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = r;
    return  h;
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

int main()
{
    link *head=NULL;

    head = insert_sort_link(head, 3);
    head = insert_sort_link(head, 1);
    head = insert_sort_link(head, 4);
    head = insert_sort_link(head, 6);
    head = insert_sort_link(head, 2);
    head = insert_sort_link(head, 5);

    print_link(head);

    head = link_reverse_2(head, 4);
    print_link(head);


    return 0;
}

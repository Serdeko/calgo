#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
typedef int dataType;
typedef struct link_node{
    dataType item;
    struct link_node *next;
}link;
link *init_link(void);
//插入aitem至单链表，并返回新的单链表头结点
link *insert_link(link *head,dataType aitem);
link *link_reverse(link *head);
link *insert_sort_link(link *head,dataType aitem);
//删除aitem的节点
link *delete_one(link *head,dataType aitem);
link *delete_link(link *head,dataType aitem);
void print_link(link *head);
void free_link(link *head);
int search_link_k(link *head, int k);
int count_link(link *head);
int search_link_dk(link *head, int k);
#endif // _LINK_LIST_H_

#ifndef __LINK_LIST_H__
//#ifdef
//如果没有定义__LINK_LIST_H__，执行下面指令
#define __LINK_LIST_H__ //定义名称__LINK_LIST_H__
#undef __LINK_LIST_H__  //去除__LINK_LIST_H__的定义
typedef int dataType;
typedef struct link_node{
    dataType item;
    struct link_node *next;
}link;
link *init_link(void);
//插入aitem至单链表，并返回新的单链表头节点
link *link_reverse(link *head);
link *delete_link(link *head, dataType aitem);
link *insert_link(link *head, dataType aitem);
link *insert_sort_link(link *head, dataType aitem);
//删除aitem的节点
link *delete_one(link *head, dataType aitem);
void print_link(link *head);
void free_link(link *head);
int search_k(link *head, int k);
#endif // __LINK_LIST_H__

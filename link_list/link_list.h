#ifndef __LINK_LIST_H__
//#ifdef
//���û�ж���__LINK_LIST_H__��ִ������ָ��
#define __LINK_LIST_H__ //��������__LINK_LIST_H__
#undef __LINK_LIST_H__  //ȥ��__LINK_LIST_H__�Ķ���
typedef int dataType;
typedef struct link_node{
    dataType item;
    struct link_node *next;
}link;
link *init_link(void);
//����aitem���������������µĵ�����ͷ�ڵ�
link *link_reverse(link *head);
link *delete_link(link *head, dataType aitem);
link *insert_link(link *head, dataType aitem);
link *insert_sort_link(link *head, dataType aitem);
//ɾ��aitem�Ľڵ�
link *delete_one(link *head, dataType aitem);
void print_link(link *head);
void free_link(link *head);
int search_k(link *head, int k);
#endif // __LINK_LIST_H__

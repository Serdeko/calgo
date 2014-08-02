#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
typedef int item_type;
typedef struct link_node{
    item_type item;
    sturct link_node *next;
}link_node;
void init_link_node(int num);
link_node new_link_node(int num);
void free_link_node(link_node link);
void insert_next(link_node link, link_node next);
link_node delete_next(link_node node);
link_node next(link_node link);
int item();
#endif // __LINK_LIST_H__

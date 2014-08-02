#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *new_node(node *head, int data)
{
    node *tmp = malloc(sizeof(node));
    tmp->data = data;
    tmp->next = head;
    return tmp;
}
node *s[4];
int visited[4];
void graph_d(int k)
{
    node *tmp = NULL;
    printf("%d\n", k);
    visited[k] = 1;
    for(tmp = s[k]; tmp != NULL; tmp = tmp->next)
        if(visited[tmp->data] == 0)
            graph_d(tmp->data);
}
void graph_d1(int k)
{
    int t = -1;
    node *tmp = NULL;
    stack_push(k);
    while(!stack_empty){
        t = stack_pop();
        printf("%d", s[t]->data);
        for(tmp = s[t]; tmp != NULL; tmp = tmp->next)
            if(visited[tmp->data] == 0)
                stack_push(tmp->data);
    }
}
void graph_g(int k)
{
    int t = -1;
    node *tmp = NULL;
    queue_put(k);
    while(!queue_empty){
        t = queue_get();
        printf("%d", s[t]->data);
        for(tmp = s[t]; tmp != NULL; tmp = tmp->next)
            if(visited[tmp->data] == 0)
                stack_push(tmp->data);
    }
}
int main()
{
    s[0] = new_node(s[0], 1);
    s[0] = new_node(s[0], 2);
    s[1] = new_node(s[1], 2);
    s[2] = new_node(s[2], 0);
    s[2] = new_node(s[2], 1);
    s[2] = new_node(s[2], 3);
    s[3] = new_node(s[3], 2);
    graph_d(0);
    return 0;
}

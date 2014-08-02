#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#define V 12
typedef struct node *link;
struct node{
    int v;
    link next;
};
int visited[V];
link adj[V];
void traverse1(int k)
{
    link t;
    printf("%d\n", k);
    visited[k] = 1;
    for(t = adj[k]; t != NULL; t = t->next)
        if(!visited[t->v])
            traverse1(t->v);
}
void traverse12(int k)
{
    link t;
    stack_push(k);
    while(!stack_empty()){
        if(visited[k = stack_pop()] == 0){
            printf("%d\n", k);
            visited[k] = 1;
            for(t = adj[k]; t != NULL; t = t->next)
                if(visited[t->v] == 0)
                    stack_push(t->v);
        }
    }
}
void traverse2(int k)
{
    link t;
    queue_put(k);
    while(!queue_empty()){
        if(visited[k = queue_get()] == 0){
            printf("%d\n", k);
            visited[k] = 1;
            for(t = adj[k]; t != NULL; t = t->next)
                if(visited[t->v] == 0)
                    queue_put(t->v);
        }
    }
}

link NEW(int v, link next)
{
    link x = malloc(sizeof *x);
    x->v = v; x->next = next;
    return x;
}
int main()
{
    int i;
    for (i = 0; i < V; i++)
        adj[i] = NULL;
    adj[0] = NEW(1, adj[0]);
    adj[0] = NEW(2, adj[0]);
    adj[1] = NEW(2, adj[1]);
    adj[2] = NEW(0, adj[2]);
    adj[2] = NEW(3, adj[2]);
    adj[3] = NEW(2, adj[3]);
    //traverse12(0);
    traverse12(0);
    return 0;
}


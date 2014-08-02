#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    int ltag, rtag;
    struct node *left;
    struct node *right;
}node;
node *pre;
void create_tree(node **t, char ch)
{
    if(*t == NULL){
        *t = (node *)malloc(sizeof(node));
        (*t)->data = ch;
        (*t)->left = NULL;
        (*t)->right = NULL;
    }else if((*t)->left == NULL)
        create_tree(&(*t)->left, ch);
    else
        create_tree(&(*t)->right, ch);
}
void inth_reading(node **p)
{
    if(*p){
        inth_reading(&((*p)->left));
        (*p)->ltag = ((*p)->left)?0:1;
        (*p)->rtag = ((*p)->right)?0:1;
        if(pre){
            if(pre->rtag==1)
                pre->right=*p;
            if((*p)->ltag==1)
                (*p)->left=pre;
        }
        pre = *p;
        inth_reading(&((*p)->right));
    }
}
node *print1(node *p)
{
    node *q;
    if(p->rtag == 1)
        return p->right;
    else{
        q = p->left;
        while(q->ltag == 0)
            q = q->left;
        return q;
    }
}
void print2(node *p)
{
    if(p){
        while(p->ltag == 0)
            p = p->left;
        do{
            printf("%c ", p->data);
            p = print1(p);
        }while(p);
    }
}
int main()
{
    node *tree = NULL;
    create_tree(&tree, '-');
    create_tree(&tree, '+');
    create_tree(&tree, '/');
    create_tree(&tree, 'a');
    create_tree(&tree, '*');
    create_tree(&tree, 'e');
    create_tree(&tree, 'f');
    create_tree(&tree, 'b');
    create_tree(&tree, '-');
    create_tree(&tree, 'c');
    create_tree(&tree, 'd');
    inth_reading(&tree);
    print2(tree);

    return 0;
}

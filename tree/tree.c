#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"
tree *tree_insert(tree *btree, int data)
{
    if(!btree){
        btree = calloc(1, sizeof(tree));
        btree->data = data;
        return btree;
    }
    if(btree->data > data)
       btree->left = tree_insert(btree->left, data);
    else
       btree->right = tree_insert(btree->right, data);
    return btree;
}
void tree_traverse1(tree *btree)
{
    if(!btree)
        return;
    printf("%d ", btree->data);
    tree_traverse1(btree->left);
    tree_traverse1(btree->right);
}
void tree_traverse2(tree *btree)
{
    if(!btree)
        return;
    tree_traverse2(btree->left);
    printf("%d ", btree->data);
    tree_traverse2(btree->right);
}
void tree_traverse3(tree *btree)
{
    if(!btree)
        return;
    tree_traverse3(btree->left);
    tree_traverse3(btree->right);
    printf("%d ", btree->data);
}
void tree_traverse_s(tree *btree)
{
    stack_push(btree);
    while(!stack_empty()){
        printf("%d ", (btree = stack_pop())->data);
        if(btree->right != NULL)
            stack_push(btree->right);
        if(btree->left != NULL)
            stack_push(btree->left);
    }
}
void tree_traverse_s1(tree *btree)
{
    while(btree || !stack_empty()){
        while(btree != NULL){
            printf("%d ", btree->data);
            stack_push(btree);
            btree = btree->left;
        }
        if(!stack_empty()){
            btree = stack_pop();
            btree = btree->right;
        }
    }
}
void tree_traverse_s2(tree *btree)
{
    while(btree || !stack_empty()){
        while(btree != NULL){
            stack_push(btree);
            btree = btree->left;
        }
        if(!stack_empty()){
            printf("%d ", (btree = stack_pop())->data);
            btree = btree->right;
        }
    }
}
void tree_traverse_s3(tree *btree)
{
    tree *pre = NULL;
    stack_push(btree);
    while(!stack_empty()){
        btree = stack_top();
        if((btree->left == NULL && btree->right == NULL) ||
              (pre != NULL &&(pre == btree->left || pre == btree->right))){
            printf("%d ", btree->data);
            stack_pop();
            pre = btree;
        }else{
            if(btree->right != NULL)
                stack_push(btree->right);
            if(btree->left != NULL)
                stack_push(btree->left);
        }
    }
}
void tree_traverse_cq(tree *btree)
{
    queue_put(btree);
    while(!queue_empty()){
        printf("%d ", (btree = queue_get())->data);
        if(btree->left != NULL)
            queue_put(btree->left);
        if(btree->right != NULL)
            queue_put(btree->right);
    }
}
int tree_count(tree *btree)
{
    if(!btree)
        return 0;
    return tree_count(btree->left) + tree_count(btree->right) + 1;
}
int tree_height(tree *btree)
{
    int left, right;
    if(!btree)
        return 0;
    left = tree_height(btree->left);
    right = tree_height(btree->right);
    if(left > right)
        return left+1;
    else
        return right+1;
}

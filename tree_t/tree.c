#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"
node *build_tree(node *tree, int data)
{
    if(tree == NULL){
        tree = malloc(sizeof(node));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    }else if(tree->data > data)
        tree->left = build_tree(tree->left, data);
    else
        tree->right = build_tree(tree->right, data);
    return tree;
}
void print_tree1(node *tree)
{
    if(tree == NULL)
        return;
    printf("%d ", tree->data);
    print_tree1(tree->left);
    print_tree1(tree->right);
}
void print_tree2(node *tree)
{
    if(tree == NULL)
        return;
    print_tree2(tree->left);
    printf("%d ", tree->data);
    print_tree2(tree->right);
}
void print_tree3(node *tree)
{
    if(tree == NULL)
        return;
    print_tree3(tree->left);
    print_tree3(tree->right);
    printf("%d ", tree->data);
}
void print_tree_s(node *tree)
{
    stack_push(tree);
    while(!stack_empty()){
        printf("%d ",(tree = stack_pop())->data);
        if(tree->right)
            stack_push(tree->right);
        if(tree->left)
            stack_push(tree->left);
    }
}
void print_tree_s1(node *tree)
{
    while(tree || !stack_empty()){
        while(tree){
            printf("%d ", tree->data);
            stack_push(tree);
            tree = tree->left;
        }
        if(!stack_empty()){
            tree = stack_pop();
            tree = tree->right;
        }
    }
}
void print_tree_s2(node *tree)
{
    while(tree || !stack_empty()){
        while(tree){
            stack_push(tree);
            tree = tree->left;
        }
        if(!stack_empty()){
            printf("%d ",
                   (tree = stack_pop())->data);
            tree = tree->right;
        }
    }
}
void print_tree_s3(node *tree)
{
    stack_push(tree);
    node *pre = NULL;
    while(!stack_empty()){
        tree = stack_top();
        if((tree->left == NULL&&tree->right == NULL)
           ||(pre != NULL&&
              (pre == tree->left||pre == tree->right))){
            printf("%d ", tree->data);
            stack_pop();
            pre = tree;
        }else{
            if(tree->right != NULL)
                stack_push(tree->right);
            if(tree->left != NULL)
                stack_push(tree->left);
        }
    }
}
//计算tree的节点数
//tree_count(tree) ----- tree_count(tree->left)+(right)+1
int tree_count(node *tree)
{
    if(tree == NULL)
        return 0;
    return tree_count(tree->left)+tree_count(tree->right)+1;
}
int tree_height(node *tree)
{
    if(tree == NULL)
        return 0;
    int lh, rh;
    lh = tree_height(tree->left);
    rh = tree_height(tree->right);
    return lh>rh ? lh+1 : rh+1;
}

void print_tree_c(node *tree)
{
    queue_put(tree);
    while(!queue_empty()){
        printf("%d ", (tree = queue_get())->data);
        if(tree->left != NULL)
            queue_put(tree->left);
        if(tree->right != NULL)
            queue_put(tree->right);
    }
}












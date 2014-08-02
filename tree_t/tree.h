#ifndef __TREE_H__
#define __TREE_H__
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *build_tree(node *tree, int data);
void print_tree1(node *tree);
void print_tree2(node *tree);
void print_tree3(node *tree);
void print_tree_s(node *tree);
void print_tree_s1(node *tree);
void print_tree_s2(node *tree);
void print_tree_s3(node *tree);
int tree_height(node *tree);
int tree_count(node *tree);

void print_tree_c(node *tree);

#endif // __TREE_H__

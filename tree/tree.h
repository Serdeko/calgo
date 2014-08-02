#ifndef __TREE_H__
#define __TREE_H__
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}tree;
tree *tree_insert(tree *btree, int data);
void tree_traverse1(tree *btree);
void tree_traverse2(tree *btree);
void tree_traverse3(tree *btree);
void tree_traverse_s(tree *btree);
void tree_traverse_s1(tree *btree);
void tree_traverse_s2(tree *btree);
void tree_traverse_s3(tree *btree);
void tree_traverse_q(tree *btree);
void tree_traverse_cq(tree *btree);
void tree_traverse_cs(tree *btree);
int tree_count(tree *btree);
int tree_height(tree *btree);
#endif // __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
    node *tree = NULL;
    tree = build_tree(tree, 12);
    tree = build_tree(tree, 14);
    tree = build_tree(tree, 8);
    tree = build_tree(tree, 6);
    tree = build_tree(tree, 11);
    tree = build_tree(tree, 15);
    tree = build_tree(tree, 9);
    tree = build_tree(tree, 13);
    printf("µ›πÈ«∞–Ú  £∫");
    print_tree1(tree);
    printf("\n");
    printf("µ›πÈ÷––Ú  £∫");
    print_tree2(tree);
    printf("\n");
    printf("µ›πÈ∫Û–Ú  £∫");
    print_tree3(tree);
    printf("\n");
    printf("∑«µ›πÈ«∞–Ú£∫");
    print_tree_s(tree);
    printf("\n");
    print_tree_s1(tree);
    printf("\n");
    print_tree_s2(tree);
    printf("\n");
    print_tree_s3(tree);
    printf("\n");
    printf("%d %d\n", tree_count(tree), tree_height(tree));

    print_tree_c(tree);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main(void)
{
    link *head = init_link();

    head = insert_link(head, 10);
    head = insert_link(head, 13);
    head = insert_link(head, 8);
    head = insert_link(head, 20);
    head = insert_link(head, 21);
    head = insert_link(head, 9);

    //print_link(head);
    search_k(head, 4);
    printf("\n");
    print_link(head);

    free_link(head);
    return 0;
}

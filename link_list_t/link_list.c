

link link_reverse(link link_list)
{
    lint tmp, y = link_list, r_link = NULL;
    while(y != NULL){
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return reverse_link;
}
node *remove_node(node *head, int i)
{
    node *prev = NULL, *curr = head;
    while(curr != NULL && curr->item != i){
        prev = curr;
        curr = curr->next;
    }
    if(prev == NULL && curr->item == i)
        head = head->next;
    else
        prev->next = curr->next;
    return head;
}
void remove_node(node **head, int i)
{
    for(node **curr = head; *curr; ){
        node *next = *curr;
        if(next->item == i){
            *curr = next->next;
            free(next);
        }else
            curr = &next->next;
    }
}
node * remove_if(node * head, remove_fn rm)
{
    for (node * prev = NULL, * curr = head; curr != NULL; )
    {
        node * const next = curr->next;
        if (rm(curr))
        {
            if (prev)
                prev->next = next;
            else
                head = next;
            free(curr);
        }
        else
            prev = curr;
        curr = next;
    }
    return head;
}
dnode *insert_dnode(dnode *head, int i)
{
    dnode *p, *q;
    p = malloc();
    p->info = i;
    p->left =  NULL;
    p->right = head;
    head = p;
    return p;
}

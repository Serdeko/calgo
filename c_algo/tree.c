typedef struct node *link;
struct node
{
    item aitem;
    link left, right;
};

void traverse(link h, void (*visit)(link))
{
    if(h == NULL)
        return;
    /*前序遍历*/
    (*visit)(h);
    traverse(h->left, visit);
    traverse(h->right, visit);
    /*visit放中间为中序，后放末尾*/
}
void traverse1(link h, void (*visit)(link))
{
    /*非递归前序遍历*/
    stack_init(max);
    stack_push(h);
    while(!stack_empty()){
        (*visit)(h = stack_pop());
        if(h->right != NULL)
            stack_push(h-right);
        if(h->left != NULL)
            stack_push(h->right);
    }
}
void traverse_c(link h, void (*visit)(link))
{
    /*层序遍历非递归形式*/
    queue_init(max);
    queue_put(h);
    while(!queue_empty()){
        (*visit)(h = queue_get());
        if(h->left != NULL)
            queue_put(h->left);
        if(h->right != NULL)
            queue_put(h->right);
    }
}

int count(link h)
{
    if(h == NULL)
        return 0;
    return count(h->left) + count(h->right) + 1;
}
int height(link h)
{
    int u, v;
    if(h == NULL)
        return -1;
    u = height(h->left);
    v = height(h->right);
    return u > v ? u+1 : v+1;
}

/*深度优先搜索*/
void traverse_t(int k, void (*visit)(int))
{
    link t;
    (*visit)(k);
    visited[k] = 1;
    for(t = adj[k]; t != NULL; t = t->next)
        if(!visited[t->v])
            traverse_t(t->v, visit);
}

/*广度优先搜索*/
void traverse_t1(int k, void (*visit)(int))
{
    link t;
    queue_init(v);
    queue_put(k);
    while(!queue_empty()){
        if(visited[k = queue_get()] == 0){
            (*visit)(k);
            visited[k] = 1;
            for(t = adj[k]; t != NULL; t = t->next)
                if(visited[t->v] == 0)
                    queue_put(t->v);
        }
    }
}























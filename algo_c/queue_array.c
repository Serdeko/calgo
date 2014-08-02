#define MAX_LEN  100
static int q[MAX_LEN], g_num, g_head, g_tail;

void queue_init(void)
{
}
int queue_is_empty(void)
{
    return (g_num == 0);
}
int queue_is_full(void)
{
    return (g_num == MAX_LEN);
}
void queue_put(int t)
{
    if(queue_is_full())
        return;
    q[g_tail] = t;
    g_tail = (g_tail+1)%MAX_LEN;
    g_num++;
}
int queue_get(void)
{
    if(queue_is_empty())
        return 0;
    g_num--;
    return q[g_head++];
}

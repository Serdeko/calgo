#define MAX_LEN  100
static int s[MAX_LEN], g_num;

void stack_init(void)
{

}
int stack_is_empty(void)
{
    return (g_num == 0);
}
int stack_is_full(void)
{
    return (g_num == MAX_LEN);
}
void stack_push(int t)
{
    if(stack_is_full())
        return;
    s[g_num++] = t;
}
int stack_pop(void)
{
    if(stack_is_empty())
        return 0;
    return s[--g_num];
}

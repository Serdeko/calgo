
boolean test_and_set(boolean *target)
{
    boolean rv = *target;
    *target = TRUE;
    return rv;
}
boolean lock = FALSE;
while(TRUE){
    while(test_and_set(&lock));
    �ٽ���;
    lock = FALSE;
    ʣ����;
}


void swap(boolean *a, boolean *b)
{
    boolean tmp = *a;
    *a = *b;
    *b = tmp;
}
while(TRUE){
    key = TRUE;
    while(key == TRUE)
        swap(&lock, &key);
    �ٽ���;
    lock = FALSE;
    ʣ����;
}


boolean waiting[n];
boolean lock;

while(TRUE){
    waiting[i] = TRUE;
    key = TRUE;
    while(waiting[i] && key)
        key = test_and_set(&lock);
    waiting[i] = FALSE;
    �ٽ���;
    j = (j+1)%n;
    while((j != i) && !waiting[j])
        j = (j+1)%n;
    if(j == i)
        lock = FALSE;
    else
        waiting[j] = FALSE;
    ʣ����;
}

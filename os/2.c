int turn;//进程可以进入临界区
boolean flag[2];//表示那个进程想进入临界区
//i = 0 j = 1

while(TRUE){
    flag[0] = TRUE;
    trun = 1;
    while(flag[1] && turn == 1);//进入区
    临界区;
    flag[0] = FALSE;//退出区
    剩余区;
}
while(TRUE){
    flag[1] = TRUE;
    trun = 0;
    while(flag[0] && turn == 0);//进入区
    临界区;
    flag[1] = FALSE;//退出区
    剩余区;
}
while(TRUE){
    请求锁;
    临界区;
    释放锁;
    剩余区;
}

void p0(){
    do{
        flag[i] = TRUE;
        trun = j;
        while(flag[j] && turn == j)
        //临界区
        flag[i] = FALSE;
        //剩余区

    }while(TRUE);
}

void p1(){
    do{
        flag[i] = TRUE;
        trun = j;
        while(flag[j] && turn == j)
        //临界区
        flag[i] = FALSE;
        //剩余区

    }while(TRUE);
}
//信号量s是整数
int s;
wait(s){
    while(s <= 0);
    s--;
}
signal(s){
    s++;
}

//n个进程共享一个信号量mutex，初始化为1；
while(TRUE){
    wait(mutex);
    //critical section;
    signal(mutex);
    //remainder section;
}

//信号
typedef struct{
    int value;
    struct process *list;//进程表
}semaphore;
wait(semaphore *s){
    s->value--;
    if(s->value < 0){
        add this process to s->list;
        block();//挂起调用该函数的进程
    }
}
signal(semaphore *s){
    s->value++;
    if(s->value <= 0){
        remove a process p from s->list;
        wakeup(p);//唤醒p继续运行
    }
}

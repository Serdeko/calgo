int turn;//���̿��Խ����ٽ���
boolean flag[2];//��ʾ�Ǹ�����������ٽ���
//i = 0 j = 1

while(TRUE){
    flag[0] = TRUE;
    trun = 1;
    while(flag[1] && turn == 1);//������
    �ٽ���;
    flag[0] = FALSE;//�˳���
    ʣ����;
}
while(TRUE){
    flag[1] = TRUE;
    trun = 0;
    while(flag[0] && turn == 0);//������
    �ٽ���;
    flag[1] = FALSE;//�˳���
    ʣ����;
}
while(TRUE){
    ������;
    �ٽ���;
    �ͷ���;
    ʣ����;
}

void p0(){
    do{
        flag[i] = TRUE;
        trun = j;
        while(flag[j] && turn == j)
        //�ٽ���
        flag[i] = FALSE;
        //ʣ����

    }while(TRUE);
}

void p1(){
    do{
        flag[i] = TRUE;
        trun = j;
        while(flag[j] && turn == j)
        //�ٽ���
        flag[i] = FALSE;
        //ʣ����

    }while(TRUE);
}
//�ź���s������
int s;
wait(s){
    while(s <= 0);
    s--;
}
signal(s){
    s++;
}

//n�����̹���һ���ź���mutex����ʼ��Ϊ1��
while(TRUE){
    wait(mutex);
    //critical section;
    signal(mutex);
    //remainder section;
}

//�ź�
typedef struct{
    int value;
    struct process *list;//���̱�
}semaphore;
wait(semaphore *s){
    s->value--;
    if(s->value < 0){
        add this process to s->list;
        block();//������øú����Ľ���
    }
}
signal(semaphore *s){
    s->value++;
    if(s->value <= 0){
        remove a process p from s->list;
        wakeup(p);//����p��������
    }
}

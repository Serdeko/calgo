#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 10

int count = 0, in = 0, out = 0;
int buffer[BUFFER_SIZE];

void producer(void)
{
    int next_produced;
    while(TRUE){
        while(count == BUFFER_SIZE);
        buffer[in] = next_produced;
        in = (in+1)%BUFFER_SIZE;
        count++;
    }
}
// tmp = count;
// count = count + 1;
// a = count;

// tmp = count;
// count = count - 1;
// a = count;
void consumer(void)
{
    int next_customed;
    while(TRUE){
        while(count == 0);
        next_customed = buffer[out];
        out = (out+1)%BUFFER_SIZE;
        count--;
    }
}

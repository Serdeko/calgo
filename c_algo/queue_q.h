#ifndef __QUEUE_Q_H__
#define __QUEUE_Q_H__
typedef struct queue *queue;
queue queue_init(int);
int queue_empty(queue);
void queue_put(queue, item);
item queue_get(queue);
#endif // __QUEUE_Q_H__

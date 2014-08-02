#ifndef __QUEUE_ARRAY_H__
#define __QUEUE_ARRAY_H__
void queue_init(void);
int queue_is_empty(void);
int queue_is_full(void);
void queue_put(int t);
int queue_get(void);
#endif // __QUEUE_ARRAY_H__


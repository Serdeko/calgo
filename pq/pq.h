#ifndef __PQ__H__
#define __PQ__H__
typedef int item;
void pq_init(int);
int pq_empty();
void pq_insert(item);
item pq_delmax();
#endif // __PQ__H__

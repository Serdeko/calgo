#ifndef __ITEM_H__
#define __ITEM_H__
typedef double item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {item t = A; A = B; B = t;}
#define compexch(A, B) if(less(B, A)) exch(A, B)
item item_rand(void);
int item_scan(item *);
void item_show(item);
#endif // __ITEM_H__

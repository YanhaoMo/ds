#include <malloc.h>

#define TYPE int

typedef struct queue {
    TYPE* data;
    TYPE* head;
    TYPE* tail;
    long length;
    long cap;

} queue;

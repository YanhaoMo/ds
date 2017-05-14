#include <malloc.h>

#define TYPE int

typedef struct stack {
    TYPE* data;
    TYPE* top;
    TYPE* bottom;
    long lenght;
    long cap;
} stack;


stack* create(long cap) {
    TYPE* data = (TYPE*)malloc(sizeof(TYPE)*cap);
    stack* st = (stack*)malloc(sizeof(stack));

    st->data = data;
    st->cap = cap;
    st->lenght = 0;

    return st;
}

int destroy(stack* st) {
    free(st->data);
    free(st);
    return 0;
}

TYPE* pop(stack* st) {

}

int push(stack* st, TYPE s) {

}

long length(stack* st) {

}

int isempty(stack* st) {

}

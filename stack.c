#include <malloc.h>
#include <string.h>

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
    st->top = &(st->data[cap-1]);
    st->bottom = st->top - 1;

    return st;
}

int destroy(stack* st) {
    free(st->data);
    free(st);
    return 0;
}

TYPE* pop(stack* st) {
    if (st->lenght == 0) {
        return NULL;
    } else {
        TYPE* temp = (TYPE*)malloc(sizeof(TYPE));
        memcpy(st->top, temp, sizeof(TYPE));
        st->top --;
        st->lenght --;
        return temp;
    }
}

int push(stack* st, TYPE s) {
    if (st->lenght < st->cap) {
        st->top ++;
        *(st->top) = s;
        st->lenght ++;
        return 0;
    } else {
        return -1;
    }
}

long length(stack* st) {
    return st->lenght;
}

int isempty(stack* st) {
    if (st->lenght == st->cap) {
        return 1;
    } else {
        return 0;
    }
}

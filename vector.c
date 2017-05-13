#include <malloc.h>

#define TYPE int

typedef struct vector {
    TYPE* data;
    long length;
    long cap;
} vector;

long length(vector* v) {
    return v->length;
}

int delete(vector* v, long idx) {
    if (v->length == 0)
        return -1;
    for (int i=idx; i<v->length-1; i++) {
        v->data[i] = v->data[i+1];
    }
    v->length --;
    return 0;
}

int search(vector* v, TYPE s) {
    for (int i=0; i<v->length; i++) {
        if (v->data[i] == s) {
            return i;
        }
    }
    return -1;
}

int insert(vector* v, TYPE s) {
/* TODO 需要考虑空间是否足够*/
    if (v->length < v->cap) {
        v->data[v->length] = s;
        return 0;
    } else {
        return -1;
    }
}

TYPE* getelem(vector* v, long idx) {
    if (idx <= v->length-1) {
        return &v->data[idx];
    } else {
        return NULL;
    }
}

int isempty(vector* v) {
    if (v->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

vector* create(long cap) {
    if(cap <= 0) {
        return NULL;
    }
    vector* v = (vector*)malloc(sizeof(vector));
    if (v == NULL) {
        return NULL;
    }
    v->length = 0;
    v->cap = cap;
    v->data = (TYPE*)malloc(sizeof(TYPE)*cap);
    if(v->data == NULL) {
        free(v);
        return NULL;
    }
    return v;
}

int destroy(vector* v) {
    free(v->data);
    free(v);
    return 0;
}

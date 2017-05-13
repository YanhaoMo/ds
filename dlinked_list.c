#include <malloc.h>

#define TYPE int

typedef struct dlist_node {
    TYPE data;
    struct list_node* pre;
    struct list_node* next;
} dlist_node;

typedef struct dlinked_list {
    dlist_node* data;
    long length;
} dlinked_list;

dlinked_list* create () {
    dlinked_list* dl = (dlinked_list*)malloc(sizeof(dlinked_list));
    if (dl == NULL) {
        return NULL;
    }

    dl->data = NULL;
    dl->length = 0;
    return dl;
}

int destroy(dlinked_list* dl) {
    for (int i=0; i<dl->length; i++) {
        dlist_node

    }
}

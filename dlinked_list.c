#include <malloc.h>

#define TYPE int

typedef struct dlist_node {
    TYPE data;
    struct dlist_node* pre;
    struct dlist_node* next;
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
        dlist_node* temp = dl->data;
        dl->data = temp->next;
        free(temp);
    }
    free(dl);
    return 0;
}

int insert(dlinked_list* dl, TYPE s) {
    dlist_node* temp = (dlist_node*)malloc(sizeof(dlist_node));
    if (temp == NULL) {
        return -1;
    }
    temp->next = NULL;
    temp->data = s;

    dlist_node* tail = dl->data;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    temp->pre = tail;
    tail->next = temp;

    dl->length ++;
    return 0;
}

int delete(dlinked_list* dl, long idx) {
    if (idx <= dl->length) {
        dlist_node* target = dl->data;
        if (idx == 0) {
            dl->data = target->next;
            if (dl->data != NULL) {
                dl->data->pre = NULL;
            }
        } else {
            for (int i=0; i<=idx; i++) {
                target = target->next;
            }
            target->pre->next = target->next;
            if(target->next != NULL) {
                target->next->pre = target->pre;
            }
        }
        free(target);
        dl->length --;
        return 0;
    } else {
        return -1;
    }
}

long search(dlinked_list* dl, TYPE s) {
    dlist_node* temp = dl->data;
    long i = 0;
    while(temp->next != NULL) {
        if (temp->data == s) {
            return i;
        }
        i ++;
    }
    return -1;
}

dlist_node* getelem(dlinked_list* dl, long idx) {
    if (idx <= dl->length) {
        dlist_node* target = dl->data;
        for (int i=0; i<=idx; i++) {
            target = target->next;
        }
        return target;
    } else {
        return NULL;
    }
}

long length(dlinked_list* dl) {
    return dl->length;
}

int isempty(dlinked_list* dl) {
    if (dl->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

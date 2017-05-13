#include <malloc.h>

#define TYPE int

typedef struct list_node {
    TYPE data;
    *next struct list_node;
} list_node;

typedef struct list {
    list_node* data;
    long length;
} list;

list* create() {
    l = (list*)malloc(sizeof(list));
    if (l == NULL) {
        return NULL;
    }
    l->data = NULL;
    l->length = 0;
    return l;
}

int destroy(list* l) {
    for (int i=0; i<l->length; i++) {
        TYPE* temp = l->data;
        l->data = temp->next;
        free(temp);
    }
    free(l);
    return 0;
}

int insert(list* l, TYPE s) {
    temp = (list_node*)malloc(sizeof(list_node));
    if (temp == NULL) {
        return -1;
    }
    temp->data = s;
    temp->next = NULL;

    TYPE* tail = l->data;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    l->length ++;
    return 0;
}

TYPE* getelem(list* l, long idx) {
    if (idx <= l->length-1) {
        list_node* target = l->data;
        for (int i=0; i<=idx; i++) {
            target = target->next;
        }
        return target;
    } else {
        return NULL;
    }
}

int delete(list* l, long idx) {
    if (idx <= l->length-1) {
        if (idx == 0) {
            list_node* target = l->data;
            l->data = target->next;
            free(target);
        } else {
            list_node* target_pre;
            for (int i=0; i<=idx-1; i++) {
                target_pre = target_pre->next;
            }
            list_node* target = target_pre->next;
            target_pre->next = target->next;
            free(target);
        }
        l->length --;
        return 0;
    } else {
        return -1;
    }
}

int length(list* l) {
    return l->length;
}

int isempty(list* l) {
    if (l->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

int search(list* l, TYPE s) {
    node_list* temp = l->data;
    int i = 0;
    while(temp->next != NULL) {
        if (temp->data == s) {
            return i;
        }
        i++;
    }
    return -1;
}

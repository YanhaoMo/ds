#include <malloc.h>

#define TYPE int

typedef struct clinked_node {
    TYPE data;
    struct clinked_node* next;
} clinked_node;

typedef struct clinked_list {
    clinked_node* data;
    clinked_node* tail;
    long length;
} clinked_list;

clinked_list* create() {
    clinked_list* temp = (clinked_list*)malloc(sizeof(clinked_list));
    if (temp == NULL) {
        return NULL;
    }
    temp->data = NULL;
    temp->tail = NULL;
    temp->length = 0;

    return temp;
}

int destroy(clinked_list* cl) {
    clinked_node* tail = cl->tail;
    if (tail == NULL) {
        free(cl);
        return 0;
    }
    clinked_node* head = tail->next;
    while(head != tail) {
        clinked_node* temp = head;
        head = head->next;
        free(temp);
    }
    free(tail);
    free(cl);
    return 0;
}

int insert(clinked_list* cl, TYPE s) {
    clinked_node* temp = (clinked_node*)malloc(sizeof(clinked_node));
    temp->data = s;
    temp->next = cl->data;

    cl->tail->next = temp;
    cl->length ++;
    return 0;
}

int delete(clinked_list* cl, long idx) {
    if (idx <= cl->length) {
        if(idx == 0) {
            if (cl->length == 1) {
                free(cl->data);
                cl->data = NULL;
                cl->length = 0;
                return 0;
            } else {
                clinked_node* target = cl->data;
                cl->data = target->next;
                free(target);
                cl->tail->next = cl->data;
                return 0;
            }
        }

        clinked_node* target_pre = cl->data;
        for (int i=0; i<idx-1; i++) {
            target_pre = target_pre->next;
        }
        clinked_node* target = target_pre->next;
        target_pre->next = target->next;
        free(target);
        cl->length --;
        return 0;
    } else {
        return -1;
    }
}

clinked_node* getelem(clinked_list* cl, long idx) {
    if (idx <= cl->length) {
        clinked_node* target = cl->data;
        for (int i=0; i<idx; i++) {
            target = target->next;
        }
        return target;
    } else {
        return NULL;
    }
}

int isempty(clinked_list* cl) {
    if (cl->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

long length(clinked_list* cl) {
    return cl->length;
}

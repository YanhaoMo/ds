#include <malloc.h>

#define TYPE int

typedef struct dclink_node {
    TYPE data;
    struct dclink_node* pre;
    struct dclink_node* next;

} dclink_node;

typedef struct dclinked_list {
    dclink_node* data;
    dclink_node* tail;
    long length;
} dclinked_list;

dclinked_list* create() {
    dclinked_list* temp = (dclinked_list*)malloc(sizeof(dclinked_list));
    if (temp == NULL) {
        return NULL;
    }
    temp->data = NULL;
    temp->tail = NULL;
    temp->length = 0;
    return temp;
}

int destroy(dclinked_list* dc) {
    while(dc->data != dc->tail) {
        dclink_node* temp = dc->data;
        dc->data = temp->next;
        free(temp);
    }
    free(dc->tail);
    free(dc);
    return 0;
}

int insert(dclinked_list* dc, TYPE s) {
    dclink_node* temp = (dclink_node*)malloc(sizeof(dclink_node));
    if(temp == NULL) {
        return -1;
    }
    temp->data = s;
    if (dc->length == 0) {
        temp->next = temp;
        temp->pre = NULL;
        dc->data = temp;
        dc->tail = temp;
    } else {
        temp->pre = dc->tail;
        temp->next = dc->data;
        dc->tail = temp;
    }
    dc->length ++;
    return 0;
}

long search(dclinked_list* dc, TYPE s) {
    dclink_node* target = dc->data;
    int i = 0;
    for (; i<dc->length; i++) {
        target = target->next;
    }
    if(target->data == s) {
        return i;
    }
    return -1;
}

dclink_node* getelem(dclinked_list* dc, long idx) {
    if (idx <= dc->length) {
        dclink_node* target = dc->data;
        for (int i=0; i<idx; i++) {
            target = target->next;
        }
        return target;
    } else {
        return NULL;
    }
}

int isempty(dclinked_list* dc) {
    if (dc->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

long length(dclinked_list* dc) {
    return dc->length;
}

int deleted(dclinked_list* dc, long idx) {
    if (idx <= dc->length) {
        if(idx == 0 && dc->length == 1) {
            dc->data = NULL;
            dc->tail = NULL;
        } else {
            dclink_node* target = dc->data;
            for( int i=0; i<idx; i++) {
                target = target->next;
            }
            if (target == dc->data) {
                dc->data = target->next;
                dc->data->pre = NULL;
            } else if (target == dc->tail) {
                target->pre->next = dc->data;
            } else {
                target->pre->next = target->next;
                target->next->pre = target->pre;
            }
            free(target);
        }
        dc->length --;
        return 0;


    } else {
        return -1;
    }
}

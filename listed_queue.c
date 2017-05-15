#include <malloc.h>

#define TYPE int

typedef struct queue_node {
    TYPE data;
    struct queue_node* next;
} queue_node;

typedef struct listed_queue {
    queue_node* head;
    queue_node* tail;
    long length;
} listed_queue;

listed_queue* create() {
    listed_queue* temp = (listed_queue*)malloc(sizeof(listed_queue));
    if (temp == NULL) {
        return NULL;
    }
    temp->head = NULL;
    temp->tail = NULL;
    temp->length = 0;
    return temp;
}

int destroy(listed_queue* lq) {
    while(lq->head != NULL) {
        queue_node* temp = lq->head;
        lq->head = temp->next;
        free(temp);
    }
    free(lq);
    return 0;
}

queue_node* out(listed_queue* lq) {
    if (lq->length == 0) {
        return NULL;
    }
    queue_node* target = lq->head;
    lq->head = target->next;
    lq->length --;
    return target;
}


#include <malloc.h>

#define TYPE int

typedef struct stack_node {
    TYPE data;
    struct stack_node* next;

} stact_node;

typedef struct linked_stack {
    stack_node* top;
    long length;
} linked_stack;

linked_stack* create() {
    linked_stack* temp = (linked_stack*)malloc(sizeof(linked_stack));
    temp->length = 0;
    temp->top = NULL;
    return temp;
}

int destroy(linked_stack* ls) {
    while(ls->top != NULL) {
        stack_node* temp = ls->top;
        ls->top = temp->next;
        free(temp);
    }
    free(ls);
    return 0;
}

stack_node* pop(linked_stack* ls) {
    if(ls->length == 0) {
        return NULL;
    }
    stack_node* target = ls->top;
    ls->top = target->next;
    ls->length --;
    return target;
}

int push(linked_stack* ls, TYPE s) {
    stack_node* temp = (stack_node*)malloc(sizeof(stack_node));
    if(temp == NULL) {
        return -1;
    }
    temp->data = s;
    temp->next = ls->top;
    ls->top = temp;
    ls->length ++;
    return 0;
}

int isempty(linked_stack* ls) {
    if (ls->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

long length(linked_stack* ls) {
    return ls->length;
}

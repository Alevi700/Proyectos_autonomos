
#include <stdlib.h>

typedef struct Node{
    struct Node* next;
    void* element; 
}Node;

typedef struct Stack{
    Node* top;
    int size;
}Stack;

Stack* Init_Stack(){
    Stack* stack = malloc(sizeof(Stack));
    if(!stack) return NULL;
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int is_empty(Stack* stack){
    if(stack->size == 0){
        return 1;
    }
    return -1;
}

void push(Stack* stack, void* element){
    Node* new_node = malloc(sizeof(Node));
    if(!new_node) return;
    new_node->element = element;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
}

void* pop(Stack* stack){
    if(is_empty(stack)) return NULL;
    Node* stack_node = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    void* element = stack_node->element;
    free(stack_node);
    return element;
}

void* top(Stack* stack){
    if(is_empty(stack)) return NULL;
    return stack->top->element;
}

int size(Stack* stack){
    return stack->size;
}

void free_stack(Stack* stack){
    Node* node = stack->top;
    while(node){
        Node* tmp = node;
        node = node->next;
        free(tmp);
    }
    free(stack);
}


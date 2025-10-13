#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    struct Nodo* next;
    void* element; 
}Nodo;

typedef struct Stack{
    Nodo* top;
    int size;
}Stack;

Stack* Init_Stack(){
    Stack* stack = malloc(sizeof(Stack));
    if(!stack) return NULL;
    stack->size = 0;
    stack->top = NULL;
    return stack;
}
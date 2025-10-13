#ifndef Stack_H
#define Stack_H

typedef struct Stack Stack;
typedef struct Node Node;

Stack* Init_Stack();

void push(Stack* p, void* element);

void* pop(Stack* p);

void* top(Stack* p);

int is_empty(Stack* p);

int size(Stack* p);

void free_stack(Stack* stack);

#endif

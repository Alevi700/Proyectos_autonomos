#ifndef Stack_H
#define Stack_H

typedef struct Stack Stack;
typedef struct Nodo;

Stack* Init_Stack();

void push(Stack* p, void* element);

void pop(Stack* p, void* element);

void top(Stack* p, void* direccion);

bool is_empty(Stack* p);

int size(Stack* p);

#endif

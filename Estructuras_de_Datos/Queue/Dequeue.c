
#include <stdio.h>;

typedef struct Node{

    void* elem;
    struct Node* front;
    struct Node* back;

} Node;

typedef struct Dequeue{

    int size;
    Node* head;
    Node* tail;

} Dequeue;

int size(const Dequeue * dq){
    
    return dq->size;
}

int is_empty(const Dequeue* dq){

    if(dq->size == 0){
        return 1;
    }
    return 0;
}

void* getFirst(Dequeue* dq){

    if(is_empty(dq)){
        return NULL;
    }
    return dq->head->elem;
}

void* getLast(Dequeue* dq){

    if(is_empty(dq)){
        return NULL;
    }
    return dq->tail->elem;
}

void addFirst(void* elem, Dequeue* dq){

    Node* n = malloc(sizeof(Node));
    if(n == NULL) return;

    n->elem = elem;
    n->front = NULL;
    n->back = dq->head;

    if(is_empty(dq)){
        dq->tail = n;
    }
    else{
        dq->head->front = n;
    }
    dq->head = n;

}

void addLast(void* elem, Dequeue* dq){

    Node* n = malloc(sizeof(Node));

    if(n == NULL) return;

    n->elem = elem;
    n->back = NULL;
    n->front = dq->tail;

    if(is_empty(dq)){
        dq->head = n;
    }
    else{
        dq->tail->back = n;
    }

    dq->tail = n;

}

void* removeFirst(Dequeue* dq){

    if(is_empty(dq)) return NULL;

    Node* aux = getFirst(dq);
    void* elem = aux->elem;

    if(aux->back == NULL){
        dq->head = NULL;
        dq->tail = NULL;
    }
    else{
        dq->head = aux->back;
        dq->head->front = NULL;
    }
    dq->size--;

    free(aux);
    return elem;

}

void* removeLast(Dequeue* dq){

    if(is_empty(dq)) return NULL;

    Node* aux = getLast(dq);
    void* elem = aux->elem;

    if(aux->front == NULL){
        dq->head = NULL;
        dq->tail = NULL;
    }
    else{
        dq->tail = aux->front;
        dq->tail->back = NULL;
    }

    dq->size--;

    free(aux);
    return elem;
}

Dequeue* init_dequeue(){

    Dequeue* dq = malloc(sizeof(Dequeue));
    if(!dq) return NULL;
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;

    return dq;

}

void free_dequeue(Dequeue* dq){

    if(dq == NULL)return;

    Node* n = dq->head;
    Node* aux;

    while (n != NULL){

        aux = n->back;
        free(n);
        n = aux;
    }
    free(dq);
}

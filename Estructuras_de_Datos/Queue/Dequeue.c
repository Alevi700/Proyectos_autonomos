
typedef struct Node{

    void* elem;
    struct Node* front;
    struct Node* back;

} Node;

typedef struct Dequeue{

    int size;
    Node* first;
    Node* last;

} Dequeue;

int size(const Dequeue * dq){
    
    return dq->size;
}

int is_empty(const Dequeue* dq){

    if(dq->size == 0){
        return 1;
    }
    return -1;
}

void* getFirst(Dequeue* dq){

    return dq->first->elem;
}

void* getLast(Dequeue* dq){

    return dq->first->elem;
}


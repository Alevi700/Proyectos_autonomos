
typedef struct Node Node;
typedef struct Dequeue Dequeue;

Dequeue* init_dequeue();

int size(const Dequeue* dq);

int is_empty(const Dequeue* dq);

void addFirst(void* elem, Dequeue* dq);

void addLast(void* elem, Dequeue* dq);

void* removeFirst(Dequeue* dq);

void* removeLast(Dequeue* dq);

void* getFirst(Dequeue* dq);

void* getLast(Dequeue* dq);






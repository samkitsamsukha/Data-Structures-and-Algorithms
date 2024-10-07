#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct{
    int buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void initBuffer(CircularBuffer* cb){
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer* cb){
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer* cb){
    return cb->count == 0;
}

void enqueue(CircularBuffer* cb, int x){
    if(isFull(cb)){
        printf("The buffer is full, cannot enqueue!\n");
        return;
    }
    cb->buffer[cb->tail] = x;
    cb->tail = (cb->tail+1)%SIZE;
    cb->count++;
    printf("Enqueued %d\n", x);
}

int dequeue(CircularBuffer* cb){
    if(isEmpty(cb)){
        printf("The buffer is empty, cannot dequeue!\n");
        return -1;
    }
    int val = cb->buffer[cb->head];
    cb->head = (cb->head+1)%SIZE;
    cb->count--;
    return val;
}

void display(CircularBuffer* cb){
    if(isEmpty(cb)){
        printf("The buffer is empty!\n");
    }
    printf("Buffer contents: ");
    for(int i = 0; i<cb->count; i++){
        printf("%d ", cb->buffer[(cb->head + i)%SIZE]);
    }
    printf("\n");
}

int main(){
    CircularBuffer cb;
    initBuffer(&cb);

    enqueue(&cb, 10);
    enqueue(&cb, 20);
    enqueue(&cb, 30);
    enqueue(&cb, 40);
    enqueue(&cb, 50);

    display(&cb);

    printf("Dequeued: %d\n", dequeue(&cb));

    display(&cb);

    printf("Dequeued: %d\n", dequeue(&cb));

    display(&cb);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int count = 0;

struct queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct queue que;

void createQueue(que *q){
    q->front = -1;
    q->rear = -1;
    printf("Queue Created\n");
}

int isEmpty(que *q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    return 0;
}

int isFull(que *q){
    if(q->rear == MAX - 1){
        return 1;
    }
    return 0;
}

void enqueue(que *q, int item){
    if(isFull(q)){
        printf("Queue Overflow\n");
        exit(0);
    }
    else{
        q->front = 0;
        q->rear ++;
        q->items[q->rear] = item;
        printf("%d enqueued\n", item);
    }
    count ++;
}

void deQueue(que *q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        exit(0);
    }
    else{
        printf("%d dequeued\n", q->items[q->front]);
        q->front ++;
        if(q->front > q->rear){
            q->front = -1;
            q->rear = -1;
        }
        count --;
    }
}

void printQueue(que *q){
    printf("Queue:\n");
    for(int i = q->front; i <= q->rear; i ++){
        printf("%d\n", q->items[i]);
    }
}

int main(){
    que *q = (que *)malloc(sizeof(que));
    createQueue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    printQueue(q);
    printf("Total Items in Queue: %d\n", count);
}
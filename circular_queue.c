#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct queue que;

void createQueue(que *q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(que *q){
    if(q->front == - 1)
    return 1;
    return 0;
}

int isFull(que *q){
    if(q->front == q->rear + 1 || q->front == 0 && q->rear == MAX - 1)
    return 1;
    return 0;
}

void enqueue(que *q, int item){
    if(isFull(q)){
        printf("Queue Overflow\n");
        exit(0);
    }
    else{
        if(q->front == - 1)
        q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = item;
        printf("%d enqueued\n", item);
    }
}

void dequeue(que *q){
    if(isEmpty(q)){
        printf("Queue Underflow\n");
        exit(0);
    }
    else{
        printf("%d dequeued\n", q->items[q->front]);
        q->front = (q->front + 1) % MAX;
        if(q->front == q->rear + 1){
            q->front = -1;
            q->rear = -1;
        }
    }
}

void printQueue(que *q){
    if(isEmpty(q)){
        printf("Queue Empty\n");
        exit(0);
    }
    else{
        printf("Queue Items:\n");
        for(int i = q->front; i <=q->rear; i = (i+1) % MAX){
            printf("%d\n", q->items[i]);
        }
    }
    
}

int main(){
    que *q = (que *)malloc(sizeof(que));
    createQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);  
    enqueue(q, 100);
    printQueue(q);
}
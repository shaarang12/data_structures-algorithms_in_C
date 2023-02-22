#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void enqueue(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the Value: ");
    scanf("%d", &item);
    ptr->data = item;
    if(head == NULL){
        ptr->next = NULL;
        head = ptr;
        printf("%d enqueued\n", item);
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        printf("%d enqueued\n", item);
    }
}

void dequeue(){
    struct node *temp;
    if(head != NULL){
        printf("%d dequeued\n", head->data);
        temp = head->next;
        head = temp;
    }
    else{
        printf("Queue Underflow\n");
        exit(0);
    }
}

int isEmpty(){
    if(head == NULL)
        return 1;
        return 0;
}

void printQueue(){
    struct node *temp;
    temp = head;
    if(isEmpty()){
        printf("Queue Empty\n");
        return;
    }
    while(temp->next != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main(){
    printf("*****Queue Implementation using Linked List*****\n");
    char ch;
    while(1){
        printf("Press e to enqueue\n");
        printf("Press d to dequeue\n");
        printf("Press i to check if queue is empty\n");
        printf("Press p to print the queue\n");
        printf("Enter Your Choice: ");
        fflush(stdin);
        scanf("%c", &ch);
        switch(ch){
            case 'e':
                enqueue();
                break;
            case 'd':
                dequeue();
                break;
            case 'i':
                if(isEmpty())
                    printf("True\n");
                else   
                    printf("False\n");
                break;
            case 'p':
                printQueue();
                break;
            case '0':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Incorrect Choice\n");
                
        }
    }
    
}
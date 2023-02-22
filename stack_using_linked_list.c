#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *top = NULL;

int count = 0;

void pushStack(){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    int item;
    printf("Enter the Data to be pushed: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;
    if(head == NULL){
        head = ptr;
        top = ptr;
        printf("%d pushed\n", item);
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        top = ptr;
        printf("%d pushed\n", item);
        free(temp);
    }
    count ++;
}

void popStack(){
    struct node *temp;
    int item;
    if(head == NULL){
        printf("Stack Underflow\n");
    }
    else{
        temp = head;
        for(int i = 0; i < count - 1; i ++){
            temp = temp->next;
        }
        item = top->data;
        printf("%d popped\n", item);
        temp->next = NULL;
        top = temp;
        printf("%d\n", top->data);
        count --;
    }
}

int main(){
    pushStack();
    pushStack();
    pushStack();
    pushStack();
    popStack();
    printf("Total Items in Stack: %d\n", count);
    
    popStack();
    popStack();
}
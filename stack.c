#include<stdio.h>
#include<stdlib.h>
#define NUMS 10
int count = 0;

struct stack {
    int items[NUMS];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
    printf("Stack Created\n");
}
int isFull(st *s){
    if(s->top == NUMS - 1){
        return 1;
    }
    return 0;
}
int isEmpty(st *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}
void pushItem(st *s, int newitem){
    if(isFull(s)){
        printf("Stack Full\n");
    }
    else{
        s->top ++;
        s->items[s->top] = newitem;
        printf("Item %d Pushed\n", newitem);
    }
    count ++;
}
void popItem(st *s){
    if(isEmpty(s)){
        printf("Stack Empty\n");
    }
    else{
        printf("Popped Item: %d\n", s->items[s->top]);
        s->top --;

    }
    count --;
}
void printStack(st *s){
    printf("Printing...\n");
    for(int i = count - 1; i >= 0; i--){
        printf("\t%d\n",s->items[i]);
    }
}
int main(){
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    pushItem(s, 1);
    pushItem(s, 3);
    pushItem(s, 5);
    pushItem(s, 2);
    pushItem(s, 4);
    pushItem(s, 6);
    pushItem(s, 7);
    pushItem(s, 8);
    pushItem(s, 9);
    pushItem(s, 0);
    popItem(s);
    popItem(s);
    popItem(s);
    printStack(s);
    }
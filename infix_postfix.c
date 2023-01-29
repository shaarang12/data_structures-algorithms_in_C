#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25

int count = 0;

struct stack{
    char items[MAX];
    int top;
};
typedef struct stack st;

int opPrecedence(char ch){
    if(ch == '+' || ch == '-')
    return 1;
    else if(ch == '*' || ch == '/')
    return 2;
    else if(ch == '^')
    return 3;
    else
    return 0;
}
int isEmpty(st *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}
int isFull(st *s){
    if(s->top == MAX - 1){
        return 1;
    }
    return 0;
}
void createStack(st *s){
    s->top = -1;
}
void pushChar(st *s, char ch){
    if(isFull(s)){
        printf("Overflow!\n");
    }
    else{
        s->top ++;
        s->items[s->top] = ch;
    }
    count ++;
}
void popChar(st *s){
    if(isEmpty(s)){
        printf("Underflow\n");
    }
    else{
        s->top --;
    }
    count --;
}
int main(){
    st *s = (st *)malloc(sizeof(st));
    char infix[] = "K+L-M*N*W/U/V*T+Q";
    char postfix[sizeof(infix)];
    int j = 0;
    createStack(s);

    for(int i = 0; i < sizeof(infix); i++){
        if(infix[i] == '{' || infix[i] == '[' || infix[i] == '('){
            pushChar(s, infix[i]);
        }
        else if(infix[i] == '}' || infix[i] == ']' || infix[i] == ')'){
            if(infix[i] == '}'){
                while(s->items[s->top] != '{'){
                    postfix[j] = s->items[s->top];
                    postfix[j + 1] = '\0';
                    j ++;
                    popChar(s);
                }
                popChar(s);
            }
            else if(infix[i] == ']'){
                while(s->items[s->top] != '['){
                    postfix[j] = s->items[s->top];
                    postfix[j + 1] = '\0';
                    j ++;
                    popChar(s);
                }
                popChar(s);
            }
            else if(infix[i] == ')'){
                while(s->items[s->top] != '('){
                    postfix[j] = s->items[s->top];
                    postfix[j + 1] = '\0';
                    j ++;
                    popChar(s);
                }
                popChar(s);
            }
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            if(isEmpty(s)){
                pushChar(s, infix[i]);
            }
            else{
                if(opPrecedence(s->items[s->top]) >= opPrecedence(infix[i])){
                    postfix[j] = s->items[s->top];
                    postfix[j + 1] = '\0';
                    j ++;
                    popChar(s);
                    if(opPrecedence(s->items[s->top]) >= opPrecedence(infix[i])){
                        postfix[j] = s->items[s->top];
                        postfix[j + 1] = '\0';
                        j ++;
                        popChar(s);
                        pushChar(s, infix[i]);
                    }
                    else{
                        pushChar(s, infix[i]);
                    }
                }
                else{
                    pushChar(s, infix[i]);
                }
            }
        }
        else if(infix[i] != '\0'){
            postfix[j] = infix[i];
            postfix[j + 1] = '\0';
            j ++;
        }
        else{
            postfix[j] = s->items[s->top];
            postfix[j + 1] = '\0';
            j ++;
            popChar(s);
        }
    }
    if(!isEmpty(s)){
            while(!isEmpty(s)){
                postfix[j] = s->items[s->top];
                postfix[j + 1] = '\0';
                j ++;
                popChar(s);
            }
    }
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
}

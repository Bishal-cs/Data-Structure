#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *link;
};
struct stack *top = NULL;

int is_Empty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(int value){
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if(top == NULL){
        printf("Stack Overflow !");
        return -1;
    }
    else{
        temp -> link = top;
        top = temp;
    }
}

int POP(){
    if(is_Empty() == 1){
        return -1;
    }
    else{
        struct stack *p = top; 
        top = top -> link;
        int x = p -> data;
        p -> link = NULL;
        free(p);
        return x;
    }
}

int Peek(){
    if(top == NULL){
        printf("Stack Overflow !");
        return -1;
    }
    else{
        return top -> data;
    }
}
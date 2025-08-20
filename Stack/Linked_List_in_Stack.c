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


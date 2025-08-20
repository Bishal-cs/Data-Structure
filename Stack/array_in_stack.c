#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;

// Is full function that check the stack is full or not ---
int is_Full(){
    if(top == MAX -1)
        return 1;
    else
        return 0;
}
// Is Empty function that check the stack is empty or not ---
int is_Empty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}
// Push function is used to push data in stack ---
void PUSH(int data){
    if(is_Full() == 1){
        printf("Stack Overflow !");
        return;
    }
    else{
        
    }
} 
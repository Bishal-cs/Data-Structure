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
// Pop Function is used to free data in stack ---
int POP(){
    int y;
    if(is_Empty() == 1){
        printf("Stack Underflow !");
        return -1;
    }
    else{
        y = stack[top];
        top --;
    }
    return y;
}
// Peek Function is used to show the top of the element ---
int PEEK(){
    if(is_Empty() == 1){
        printf("Stack Underflow !");
        return -1;
    }
    return stack[top];
}
// Display function is used to Show the data in the stack ---
void Display(){
    if(is_Empty() == 1){
        printf("Stack Underflow !");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%d", stack[i]);
    }
    printf('<- top');
}
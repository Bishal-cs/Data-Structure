#include<stdio.h>
#define MAX 5
int Queue[MAX];
int F = -1, R = -1;
// is full function ---
int is_Full(){
    if(R == MAX -1){
        return 1;
    }
    else{
        return 0;
    }
}
// is Empty function ---
int is_Empty(){
    if(F == -1 && F > R){
        return 1;
    }
    else{
        return 0;
    }
}
// Enqueue Function is used to add element ---
void enqueue(int value){
    if(is_Full() == 1){
        printf("Queue Overflow! \n");
        return -1;
    }
    R++;
    Queue[R] == value;
    if(F == -1 && R == -1){
        F++;
    }
}
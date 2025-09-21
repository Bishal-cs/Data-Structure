#include<stdio.h>
#define MAX 5
int Queue[MAX];
int Front = -1, Rear = -1;

int is_Empty(){
    if(Front == -1)
        return 1;
    return 0;
}

int is_Full(){
    if(Rear == MAX -1 || Front +1 == Rear)
        return 1;
    return 0;
}

void main(){
    if(is_Empty())
        printf("Hi");
        return;
    printf("Hello");
}
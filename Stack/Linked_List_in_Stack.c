#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *link;
};
struct stack *top = NULL;
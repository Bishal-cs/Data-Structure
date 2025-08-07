#include<stdio.h>
#include<stdlib.h>
struct node{
    float Co;
    int Ex;
    struct node *link;
};
struct node *Insert(struct node *start, float Co, int Ex){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> Co = Co;
    temp -> Ex = Ex;
    if(start == NULL || Ex > start -> Ex){
        temp -> link = start;
        start = temp;
    }
    else if(Ex == start -> Ex){
        start -> Co += Co;
    }
    else{
        struct node *p = start;
        while(p -> link != NULL){
            if(p -> link -> Ex > Ex){
                p = p -> link;
            }
            else{
                break;
            }
        }
        if(p -> link == NULL){
            p -> link = temp;
            temp -> link = NULL;
        }
        else if(p -> link -> Ex == Ex){
            p -> link -> Co += Co;
        }
        else{
            temp -> link = p -> link;
            p -> link = temp;
        }
    }
    return start;
}
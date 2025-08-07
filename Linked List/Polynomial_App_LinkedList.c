#include<stdio.h>
#include<stdlib.h>
struct node{
    float Co;
    int Ex;
    struct node *link;
};
// Insert Node in polynomial app ---
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
        free(temp);
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
            free(temp);
        }
        else{
            temp -> link = p -> link;
            p -> link = temp;
        }
    }
    return start;
}
// Display in polynomial app ---
struct node *Display(struct node *start){
    struct node *st = start;
    printf("F(x) = ");
    while(st != NULL){
        printf("%.2fx^%d",st-> Co, st-> Ex);
        if(st -> link != NULL && st -> link -> Co >= (-0)){
            printf("-");
        }
        else{
            printf("+");
        }
        st = st -> link;
    }
    printf("\n");
    return start;
}
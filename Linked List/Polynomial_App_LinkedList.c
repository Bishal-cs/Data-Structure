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
            printf("+");
        }
        st = st -> link;
    }
    printf("\n");
    return start;
}
// Insert Last on Polynomial Function that is insert the value in the list what i send from addition ---
struct node *Insert_Last(struct node *start, float Co, int Ex){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> Ex = Ex;
    temp -> Co = Co;
    struct node *st = start;
    if(st == NULL){
        temp -> link = start;
        start = temp;
    }
    else{
        while(st != NULL){
            if(st -> link == NULL){
                st -> link = temp;
                temp -> link = NULL;
                break;
            }
            st = st -> link;
        }
    }
    return start;
}
// Addition of two Polynomial function ---
struct node *Addition(struct node *start1, struct node *start2, float Co, int Ex){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> Ex = Ex;
    temp -> Co = Co;
    struct node *p1 = start1, *p2 = start2;
    struct node *start3 = NULL;
    while(p1 != NULL || p2 != NULL){
        if(p1 -> Ex > p2 -> Ex){
            start3 = Insert_Last(start3, p1 -> Co, p1 -> Ex);
            p1 = p1 -> link;
        }
        else if(p1 -> Ex < p2 -> Ex){
            start3 = Insert_Last(start3, p2 -> Co, p2 -> Ex);
            p2 = p2 -> link;
        }
        else{
            float c = p1 -> Co + p2 -> Co;
            if(c != 0)
                start3 = Insert_Last(start3, c, p1 -> Ex);
            p1 = p1 -> link;
            p2 = p2 -> link;
        }
    }
    while(p1 != NULL){
        start3 = Insert_Last(start3, p1 -> Co, p1 -> Ex);
    }
    while(p2 != NULL){
        start3 = Insert_Last(start3, p2 -> Co, p2 -> Ex);
    }
    return start3;
}
// Multiplaction on Polynominal function ---
struct node *Multiplaction(struct node *start1, struct node *start2, float Co, int Ex){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> Ex = Ex;
    temp -> Co = Co;
    struct node *start3 = NULL;
    struct node *p1 = start1, p2 = start2;
    if(p1 == NULL || p2 == NULL){
        start3 = NULL;
    }
    else{
        while(p1 != NULL){
            p2 = start;
            while(p2 != NULL){
                start3 = insert(start3, p1 -> Co * p2 -> Co, p1 -> Ex + p2 -> Ex)
                p2 = p2 -> link;
            }
            p1 = p1 -> link;
        }
    }
}

// Create list in this polinomial function ---
struct node *createlist(struct node* start, int n){
    struct node *p = start;
    int i, E;
    float C;
    for(i = 1; i <= n; i++){
        printf("Enter Coefficent -> ");
        scanf("%f", &C);
        printf('Enter Exponent -> ');
        scanf("%d", &E);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp -> Co = C;
        temp -> Ex = E;
        temp -> link = NULL;
        if(start == NULL){
            start = temp;
        }
        else{
            p -> link = temp;
        }
        p = temp;
    }
    return start;
}

// display function use to display the structure the node ---
void Display(struct node *start){
    
}
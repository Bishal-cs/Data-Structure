#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *Link;
};

// Insert First in Circular Linked List ---
struct node *Insert_First(struct node *Last, int value){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    if(Last == NULL){
        temp -> Link = temp;
        Last = temp;
    }
    else{
        temp -> Link = Last -> Link;
        Last -> Link = temp;
    }
    return Last;
} 
// Display in Circular Linked List ---
struct node *Display(struct node *Last){
    struct node *st = Last -> Link;
    if(Last == NULL){
        printf("NULL <--- Last\n");
    }
    else{
        while(st != Last){
            printf("%d ---> ", st -> data);
            st = st -> link;
        }
        printf("Last\n");
    }
    return Last;
}
// Count Node in Circular Linked List
struct node *Count_Nodes(struct node *Last){
    struct node *st = Last -> Link;
    int c = 0;
    while(st != Last){
        c++;
        st = st -> link;
    }
    printf("The number of Node is -> %d", c);
    return Last;
}
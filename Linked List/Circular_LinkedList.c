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
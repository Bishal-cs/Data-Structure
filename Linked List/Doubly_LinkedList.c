#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *start = NULL;

//Delete Before element---
void Delete_Before(int value){
    if(start == NULL || start -> right == NULL || start -> data == value){
        printf("Delete Not possiable!");
    }
    else{
        struct node *curr = start->right;
        while(curr -> right != NULL){
            curr = curr -> right;
            if(curr -> data == value){
                struct node *p = curr -> left;
                if(p -> left == NULL){
                    p -> right = NULL;
                    curr -> left = NULL;
                    free(p);
                }
                else{
                    p -> left -> right = curr;
                    curr -> left = p -> left;
                    p -> right = NULL;
                    p -> left = NULL;
                    free(p);
                }
           }
        }
    }
}

int Delete_After(int value){

}
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *start = NULL;

//Delete Before element----
void Delete_Before(int value){
    if(start == NULL || start -> right == NULL || start -> data == value){
        printf("Delete Not possible!\n");
    }
    else{
        struct node *curr = start->right;
        while(curr -> right != NULL){
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
            curr = curr -> right;
        }
    }
}
// Delete After element----
void Delete_After(int value){
    if(start == NULL || start -> right == NULL){
        printf("Delete Not possible!\n");
    }
    else(
        struct node *curr = start;
        while(curr -> right != NULL){
            if(curr -> data == value){
                struct node *N = curr -> right;
                if(N == NULL){
                    printf("%d is the last node so cant delete!",curr);
                }
                else{
                    curr -> right = N -> right;
                    N -> right -> left = curr;
                    N -> right = NULL;
                    N -> left = NULL;
                    free(N);
                }
            }
            curr = curr -> right;
        }
    )
}
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *start = NULL;

// Insert First elements using doubly linked list----
void Insert_First(int value){
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp -> data = value;
    temp -> left = NULL;
    temp -> right = start;
    if(start == NULL){
        start = temp;
    }
    else{
        start -> left = temp;
        start = temp;
    }
}

// Insert End elements---
void Insert_END(int value){
    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp -> data = value;
    temp -> right = NULL;
    if(start == NULL){
        temp -> left = NULL;
        start = temp;                                          
    }
    else{
        struct node *curr = start;
        while(curr -> right != NULL){
            curr = curr -> right;
        }
        curr -> right = temp;
        temp -> left = curr;
    }
}

// Insert After element----
void Insert_After(int value, int AfterValue){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    if(start == NULL){
        printf("List is empty. Cannot insert after %d\n", AfterValue);
        return;
    }
    else{
        struct node *p = start;
        while(p != NULL){
            if(p -> data == AfterValue){
                temp->right = p->right;
                if(p -> right != NULL){
                    p -> right -> left = temp;
                }
                p -> right = temp;
                temp -> left = p;
                return;        
            }
            p = p -> right;
        }
        printf("Data not found %d", AfterValue);
    }
}
// Insert Before Node ---
void Insert_Before(int value, int BV){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    if(start == value){
        printf("Data not delete!");
    }
    else{
        struct node *p = start;
        while(p != NULL){
            if(p -> data == BV){
                struct node *q = p -> left;
                temp -> right = p;
                temp -> left = q;
                p -> left = temp;
                if(q == NULL){
                    start = temp;
                }
                else{
                    q -> right = temp;
                }
            }
            p = p -> right;
        }
        printf("Data- %d not found!", BV);
    }
}
// Insert Position Node ---
// Node Count ---
// Search Node ---
// Delete First Node ---
// Delete Last Node ---

/*// Delete Before element----
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
} This need to modify.*/

// Delete After element----
/* This method i created other in the note book.*/
int Delete_After(int value){
    int x = -1;
    if(start == NULL || start -> right == NULL){
        printf("Delete Not possible!\n");
    }
    else{
        struct node *curr = start;
        while(curr -> right != NULL){
            if(curr -> data == value){
                struct node *N = curr -> right;
                if(N == NULL){
                    if(curr -> data == value){
                        printf("Data Found but not delete!");
                    }
                    else{
                        printf("Data Not Delete!");
                    }
                }
                else{
                    curr -> right = N -> right;
                    if(N -> right != NULL){
                        N -> right -> left = curr;
                    }
                    N -> right = N -> left = NULL;
                    x = N -> data;
                    free(N);
                }
            }
            curr = curr -> right;
        }
    }
    return x;
}

//Delete Match element or node ---
void Delete_Match_value(int value){
    struct node *p = start;
    if(start == NULL){
        printf("Delete not possible!");
    }
    else if(start -> data == value){
        start = start -> right;
        if(start != NULL){
            start -> left = NULL;
        }
        p -> right = NULL;
        free(p);
    }
    else{
        while(p != NULL){
            if(p -> data == value){
                p -> left -> right = p -> right;
                if(p -> right != NULL){
                    p -> right -> left = p -> left;
                }
                p -> left = p -> right = NULL;
                free(p);
            }
            p = p -> right;
        }
        if(p == NULL){
            printf("Data Not Found!");
        }
    }
}
// Create Node in Doubly linked list ---
int Create_Doubly_List(int num){
    int values;
    for(int i=1; i<=num; i++){
        printf("Enter values :: ");
        scanf("%d", &values);
    }
}
// Main function of the Doubly Linked List ---
int main(){
    int key, n;
    printf("Enter the number of nodes to creat: ");
    scanf("%d", &n);
    Create_Doubly_List(n)
    while(1){
        // Print the Functions names in doubly linked list. 
        printf("\n=== Doubly Linked List Menu ===\n");

        // start the calling of the functions and run this with switch case:
        scanf("%d", &key);
        switch(key){
            case 1:
                printf("dsjngjsr");
        }
    }
}
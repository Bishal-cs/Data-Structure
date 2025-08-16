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
    if(start -> data == BV){
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
                return;
            }
            p = p -> right;
        }
    }
    printf("Data- %d not found!", BV);
}

// Insert Position Node ---
void Insert_Position_Node(int value, int pos){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    struct node *p = start;
    if(start == NULL){
        printf("Doubly Linked List Empty!");
        return;
    }
    else if(pos == 1){
        temp -> right = start;
        temp -> left = NULL;
        start -> left = temp;
        start = temp;
    }
    else{
        for(int i=1;i<=(pos-2) && p!=NULL; i++)
            p = p -> right;
        if(p == NULL){
            printf("Position Not found");
        }
        else{
            struct node *q = p -> right;
            temp -> right = q;
            temp -> left = p;
            p -> right = temp;
            if(q != NULL)
                q -> left = temp;
        }
    }
}
// Node Count ---
int Node_Count(){
    struct node *st = start;
    int c = 0;
    while(st != NULL){
        c++;
        st = st -> right;
    }
    return c;
}

// Search Node ---
int Search_Value(int value){
    int c = 0;
    struct node *st = start;
    while(st != NULL){
        if(st -> data == value){
            return c;
        }
        st = st -> right;
    }
    return -1;
}

// Delete First Node ---
void Delete_First(){
    int x;
    if(start == NULL){
        printf("Doubly Linked List Empty!");
    }
    else{
        struct node *p = start;
        x = start -> data;
        start = start -> right;
        if(start != NULL){
            start -> left = NULL;
            p -> right = NULL;
            free(p);
        }
    }
}

// Delete Last Node ---
void Delete_Last(){
    int x;
    struct node *p = start;
    if(start == NULL){
        printf("Doubly Linked List Empty!");
    }
    else if(start -> right == NULL){
        x = start -> data;
        start = start -> right;
        free(p);
    }
    else{
        while(p -> right != NULL){
            p = p -> right;
        }
        p -> left -> right = NULL;
        p -> left = NULL;
        free(p);
    }
}

// Delete Before element----
int Delete_Before(int value){
    int x = -1;
    if(start == NULL || start -> data == value){
        printf("Delete Not possible!\n");
    }
    else{
        struct node *curr = start;
        if(start -> right -> data == value){
            start = curr -> right;
            curr -> right = NULL;
            start -> left = NULL;
            x = curr -> data;
            free(curr);
        }
        else{
            while(curr != NULL){
                if(curr -> data == value){
                    struct node *q = curr -> left, *r = q -> left;
                    r -> right = curr;
                    curr -> left = r;
                    q -> left = q -> right = NULL;
                    x = q -> data;
                    free(q);
                }
                curr = curr -> right;
            }
            if(curr == NULL){
                printf("Data Not Found!");
            }
        }
    }
    return x;
}

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

// Delete Position Value ---
int Delete_Position(int pos){
    int x = -1;
    if(start == NULL){
        printf("Start have no data.");
    }
    else if(pos == 1){
        struct node *p = start;
        start = start -> right;
        x = p -> data;
        free(p);
    }
    else{
        struct node *p = start;
        for(int i = 1; i < pos && p!= NULL; i++){
            p = p -> right;
        }
        if(p == NULL){
            printf("%d Position not found.",pos);
        }
        else{
            p -> left -> right = p -> right;
            if(p -> right != NULL)
                p -> right -> left = p -> left;
            p -> left = NULL;
            x = p -> data;
            free(p);
        }
    }
    return x;
}

// Display Doubly link list ---
void Display(){
    struct node *st = start;
    printf("NULL <--- Start <---->");
    while(st != NULL){
        printf("%d <----> ",st->data);
        st = st -> right;
    }
    printf("NULL.\n");
}

// Create Node in Doubly linked list ---
void Create_Doubly_List(int num){
    int values;
    struct node *N, *p = NULL;
    for(int i=1; i<=num; i++){
        printf("Enter values :: ");
        scanf("%d", &values);
        N = (struct node *)malloc(sizeof(struct node));
        N -> data = values;
        N -> left = N -> right = NULL;
        if(start == NULL){
            start = N;
        }
        else{
            p -> right = N;
            N -> left = p;
        }
        p = N;
    }
}
/*Some Special Question In Single Linked List*/
// W.A.P to swap the First and Last Element of Doubly linked list without swap the data.
void Swap_First_Last(){
    if(start == NULL || start -> right == NULL){
        printf("Swap Not possible.\n");
        return;
    }
    struct node *last = start, *prev = NULL;
    while(last -> right != NULL){
        prev = last;
        last = last -> right;
    }
    last -> right = start -> right;
    prev -> right = start;
    start -> right = NULL;
    start = last;
    printf("Swap Success.\n");
}
// Main function of the Doubly Linked List ---
int main(){
    int key, n;
    int arg1, arg2;
    printf("Enter the number of nodes to creat: ");
    scanf("%d", &n);
    Create_Doubly_List(n);
    while(1){
        // Print the Functions names in doubly linked list. 
        printf("\n=== Doubly Linked List Menu ===\n");
        printf("Press 1  Insert at Beginning (Insert_First)\n");
        printf("Press 2  Insert at End (Insert_END)\n");
        printf("Press 3  Insert After a Value (Insert_After)\n");
        printf("Press 4  Insert Before a Value (Insert_Before)\n");
        printf("Press 5  Insert at Position (Insert_Position_Node)\n");
        printf("Press 6  Count Nodes (Node_Count)\n");
        printf("Press 7  Search a Value (Search_Value)\n");
        printf("Press 8  Delete First Node (Delete_First)\n");
        printf("Press 9 Delete Last Node (Delete_Last)\n");
        printf("Press 10 Delete Before a Value (Delete_Before)\n");
        printf("Press 11 Delete After a Value (Delete_After)\n");
        printf("Press 12 Delete Specific Value (Delete_Match_value)\n");
        printf("Press 13 Delete Position Value(Delete_Position)\n");
        printf("Press 14 Display List (Display)\n");
        printf("Press 15 swap the First and Last Element.\n");
        printf("Press any other key to Exit\n");

        // start the calling of the functions and run this with switch case:
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("Enter Number to Insert at Beginning ->");
                scanf("%d", &arg1);
                Insert_First(arg1);
                break;
            case 2:
                printf("Enter Number to Insert at End ->");   
                scanf("%d", &arg1);
                Insert_END(arg1);
                break;
            case 3:
                printf("Enter Number to Insert After Value ->");
                scanf("%d", &arg1);
                printf("Enter Value to Insert After ->");
                scanf("%d", &arg2);
                Insert_After(arg1, arg2);
                break;
            case 4:
                printf("Enter Number to Insert Before Value ->");
                scanf("%d", &arg2);
                printf("Enter Value to Insert Before ->");
                scanf("%d", &arg1);
                Insert_Before(arg2, arg1);
                break;
            case 5:
                printf("Enter Value to Insert at Position ->");
                scanf("%d", &arg1);
                printf("Enter Position to Insert ->");
                scanf("%d", &arg2);
                Insert_Position_Node(arg1, arg2);
                break;
            case 6:
	            printf("Node count: %d\n", Node_Count());
                break;
            case 7:
                printf("Enter any value to search from your node ::");
                scanf("%d", &arg1);
                Search_Value(arg1);
                break;
            case 10:
                printf("Enter Value to delete before value ->");
                scanf("%d", &arg1);
                Delete_Before(arg1);
                break;
            case 13:
                printf("Enter position value to delete ->");
                scanf("%d", &arg1);
                Delete_Position(arg1);
                break;
            case 14:
                printf("Displaying the all list ->\n");
                Display();
                break;
            case 15:
                Swap_First_Last();
                Display();
                break;
            default:
                printf("Exiting...\n");
                exit(0);
                break;
        }
    }
}
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
    printf("%d The number Successfull Insert At First Position.", value);
    return Last;
} 
// Insert Last in Circular Linked List ---
struct node *Insert_Last(struct node *Last, int value){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    if(Last == NULL){
        temp -> Link = temp;
        Last = temp;
    }
    else{
        temp -> Link = Last -> Link;
        Last -> Link = temp;
        Last = temp;
    }
    printf("%d The number Successfull Insert At Last Position.", value);
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
            st = st -> Link;
        }
        printf("Last\n");
    }
    return Last;
}
// Count Node in Circular Linked List ---
struct node *Count_Nodes(struct node *Last){
    struct node *st = Last -> Link;
    int c = 0;
    while(st != Last){
        c++;
        st = st -> Link;
    }
    printf("The number of Node is -> %d", c);
    return Last;
}
// Search Node in Circular Linked List ---
struct node *Search_Node(struct node *Last, int value){
    int c = 0;
    struct node *st = Last -> Link;
    while(st != Last){
        c++;
        if(st -> data == value){
            printf("Data %d found at position %d\n", value, c);
        }
        else{
            printf("Data not found. In the list.");
        }
        st = st -> Link;
    }
    return Last;
}
// Delete First in Circular Linked List ---
struct node *Delete_First(struct node *Last){
    int Data = 0;
    if(Last == NULL || Last -> Link = Last){
        printf("Delete Not possible.");
    }
    else{
        struct node *p = Last -> Link, q = p -> Link;
        Last -> Link = q;
        p -> Link = NULL;
        Data = p -> data;
        free(p)
        printf("Success Fully Deleted First Element the data is %d", Data);
    }
    return Last;
}
// Delete Last in Circular Linked List ---
struct node *Delete_last(struct node *Last){
    int Data = 0;
    if(Last == NULL || Last -> Link = Last){
        printf("Delete Not possible.");
    }
    else{
        struct node *p = Last;
        while(p -> Link != Last){
            p = p -> Link;
        }
        struct node *q = p -> Link;
        Last = Last -> Link;
        p -> Link = Last;
        q -> Link = NULL;
        Data = q -> data;
        free(q);
        printf("Success Fully Deleted Last Element the data is %d", Data);
    }
    return Last;
}
// Insert Postition in Circular Linked List ---
struct node *Insert_position(struct node *Last, int value, int position){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    if(Last == NULL){
        temp -> Link = NULL;
        Last = temp;
        Last -> link = Last;
    }
    else{
        struct node *p = Last -> Link;
        int i = 1;
        for(i =1; i <position -1; i++){
            if(p != Last){
                p = p -> Link;
            }
            else
                break;
        }if (i < (position - 2)){
            printf("Position is out of range\n");
        }else{
            struct node *q = p -> Link;
            temp -> Link = q;
            p -> link = temp;
        }
    }
    return Last;
}
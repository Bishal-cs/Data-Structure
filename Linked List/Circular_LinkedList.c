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
    printf("\n%d The number Successfull Insert At First Position.", value);
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
    printf("\n%d The number Successfull Insert At Last Position.", value);
    return Last;
}
// Display in Circular Linked List ---
struct node *Display(struct node *Last){
    struct node *st = Last -> Link;
    if(Last == NULL){
        printf("NULL <--- Last\n");
    }
    else{
        while(st != Last -> Link){
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
    int x = 0;
    if(Last == NULL || Last -> Link == Last){
        printf("Delete Not possible.");
    }
    else{
        struct node *p = Last -> Link, *q = p -> Link;
        Last -> Link = q;
        x = p -> data;
        p -> Link = NULL;
        free(p);
        printf("Success Fully Deleted First Element the data is %d", x);
    }
    return Last;
}
// Delete Last in Circular Linked List ---
struct node *Delete_last(struct node *Last){
    int x = 0;
    if(Last == NULL || Last -> Link == Last){
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
        x = q -> data;
        free(q);
        printf("Success Fully Deleted Last Element the data is %d", x);
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
        Last -> Link = Last;
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
            p -> Link = temp;
        }
    }
    return Last;
}
// Delete Value in Circular Linked List ---
struct node *Delete_Value(struct node *Last){
    int x = 0;
    
}
// Create_Circular_Linked_List ---
struct node *Create_Circular_List(struct node *Last, int num){
    int value;
    for(int i = 0; i < num; i++){
        printf("Enter value: ");
        scanf("%d", &value);
        Last = Insert_Last(Last, value);
    }
    return Last;
}

int main(){
    int key, n;
    int value, position, searchValue;
    struct node *Last = NULL;
    printf("Enter the number of nodes to creat: ");
    scanf("%d", &n);
    Last = Create_Circular_List(Last, n);
    while(1){
        printf("\n=== Circular Linked List Menu ===\n");
        printf("Press 1  Insert First (Insert_First)\n");
        printf("Press 2  Insert Last (Insert_Last)\n");
        printf("Press 3  Insert at Position (Insert_position)\n");
        printf("Press 4  Display List (Display)\n");
        printf("Press 5  Count Nodes (Count_Nodes)\n");
        printf("Press 6  Search Node (Search_Node)\n");
        printf("Press 7  Delete First Node (Delete_First)\n");
        printf("Press 8  Delete Last Node (Delete_last)\n");
        printf("Press 9  Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch(key){
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &value);
                Last = Insert_First(Last, value);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                Last = Insert_Last(Last, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                Last = Insert_position(Last, value, position);
                break;
            case 4:
                Last = Display(Last);
                break;
            case 5:
                Last = Count_Nodes(Last);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &searchValue);
                Last = Search_Node(Last, searchValue);
                break;
            case 7:
                Last = Delete_First(Last);
                break;
            case 8:
                Last = Delete_last(Last);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
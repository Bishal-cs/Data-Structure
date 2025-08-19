#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
};
struct node *start = NULL;

// Insert First ----------------------
void InsertFirst(int value){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(start == NULL) {
        temp->link = NULL;
        start = temp;
    }else {
        temp->link = start;
        start = temp;
    }
}
// Insert Last -----------------------
void InsertEnd(int value){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if (start == NULL) {
        temp->link = NULL;
        start = temp;
    }else if (start -> link == NULL) {
        start->link = temp;
        temp->link = NULL;
    }else {
        struct node * p = start;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
        temp->link = NULL;
    }
}
// Insert Position -------------------
void InsertPosition(int value, int position){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if (start == NULL){
        temp -> link = NULL;
        start = temp;
    }else {
        struct node * p = start, * q = start -> link;
        int i = 1;
        for(i =1; i <position -1; i++){
            if(q != NULL){
                p = p->link;
                q = q->link;
            }else
                break;
        } if (i < (position - 2)){
            printf("Position is out of range\n");
            return;
        }else {
            p ->link = temp;
            temp->link = q;
        }
    }
}
// Insert After ----------------------
void InsertAfter(int value, int afterValue){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(start == NULL){
        printf("Value %d not found in the list.\n", afterValue);
        return;
    }else{
        struct node * p = start, *q = start->link;
        while(q != NULL){
            if(p->data == afterValue){
                p -> link = temp;
                temp -> link = q;
                return;
            }else{
                p = p -> link;
                q = q -> link;
            }
        }if(p->data == afterValue){
            p -> link = temp;
            temp -> link = q;
        }
    }   
}
// Insert Before ---------------------
void InsertBefore(int value, int beforeValue){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    struct node * p = start, * q = start -> link;
    if(start == NULL){
        printf("Value %d not found in the list.\n", beforeValue);
    }else{
        while(q != NULL){
            if(q -> data == beforeValue){
                p -> link = temp;
                temp -> link = q;
            }else{
                p = p -> link;
                q = q -> link;
            }
        }if(start -> data == beforeValue){
            temp -> link = start;
            temp = start;
        }else{
            printf("Value %d not found in the list.\n", beforeValue);
        }
    }
}

// check the node number with value of the Position -------------------
int Search(int value){
    struct node *p = start;
    int c = 0;
    while(p != NULL){
        c++;
        if(p -> data == value){
            printf("Value %d found at position %d\n", value, c);
            return c;
        }
        p = p -> link;
    }
    return -1;
}

// check the node count  ----------------
int NodeCount(){
    struct node *p = start;
    int c = 0;
    while(p != NULL){
        c++;
        p = p -> link;
    }
    return c;
}
// Delete First Elements----------
int DeleteFirst(){
    int x;
    struct node * p = start;
    if(start == NULL){
        printf("List is empty\n");
        return -1;
    }else{
        x = p -> data;
        start = start -> link;
        free(p);
    }
    return x;
}
// Delete Last Elements----------
int DeleteLast_0(){
    int x;
    struct node *p = start, *q = start -> link;
    if(start == NULL){
        printf("List is empty\n");
        return -1;
    }else{
        while(q->link != NULL){
            p = p -> link;
            q = q -> link;
        }
        x = q -> data;
        p -> link = NULL;
        free(q);
    }
    return x;
}
// 2nd way to Delete Last Elements----------
int DeleteLast_1(){
    int x;
    struct node *p = start, *q = start -> link;
    if(start == NULL){
        printf("List is empty\n");
        return -1;
    }else{
        while(p -> link -> link != NULL){
            p = p -> link;
        }
        x = (p -> link) -> data;
        p -> link = NULL;
        q = p -> link;
        p -> link = NULL;
        free(q);
    }
    return x;
}
//  Delete Before value of the given value ----------
int DeleteBefore(int value){
    int x = -1;
    if(start == NULL || start -> link == NULL || start -> data == value){
        printf("There is No node");
    }
    else{
        struct node *p = start, *q = start -> link, *r = q ->link;
        if(q -> data == value){
            start = q;
            x = q -> data;
            p -> link = NULL;
            free(p);
        }
        else{
            while(r != NULL){
                if(r -> data == value){
                    p -> link = r;
                    x = q -> data;
                    q -> link = NULL;
                    free(q);
                    break;
                }
                p = p -> link;
                q = q -> link;
                r = r -> link;
            }
            if(r == NULL){
                printf("Value Not found !");
            }
        }
    }
    return x;
}
// delete after given value ---------
void DeleteAfter(int value){
    struct node *p = start, *q = start -> link, *r = q ->link;
    if(start == NULL || start -> link == NULL){
        printf("There is No node");
    }
    else{
        while(r != NULL){
            if(p -> data == value){
                p -> link = r;
                q -> link = NULL;
                free(q);
                break;
            }
            p = p -> link;
            q = q -> link;
            r = r -> link;
        }
        if(q == NULL){
            if(p -> data == value){
                printf("data %d is founded but not deleted. ! ", value);
            }
            else{
                printf("Data Not Delete. !");
            }
        } 
    }
}
// Delete Specific given value -------------
void DeleteSpecificValue(int value){
    if(start == NULL){
        printf("Start is NULL !");
    }
    else{
        struct node *p = start, *q = start -> link;
        if(p -> data == value){
            start = q;
            p -> link = NULL;
            free(p);
        }
        else{
            while(q != NULL){
                if(q -> data == value){
                    p -> link = q -> link;
                    q -> link = NULL;
                    free(q);
                    break;
                }
                p = p -> link;
                q = q -> link;
            }
            if(q == NULL){
                printf("Data Not found !");
            }
            
        }
    }
}
// List Display Function------------
void Display_List(){
    struct node *st = start;
    printf("Start ---> ");
    while(st != NULL){
        printf("%d ---> ", st->data); // Print node data and arrow
        st = st->link;
    }
    printf("NULL\n");
}
// Create New List from start ---------
void create_List(int n){
    int i, v;
    struct node *N, *p = NULL;
    for(i = 1; i<=n; i++){
        printf("Enter values :: ");
        scanf("%d", &v);
        N = (struct node *)malloc(sizeof(struct node)); // Allocate inside loop
        N->data = v;
        N->link = NULL;
        if(start == NULL){
            start = N;
        }
        else{
            p->link = N;
        }
        p = N;
    }
}
/*Some Special Question In Single Linked List*/
// Write A Program To Find Smallest & Largest Number in Single Linked List ---
void Smallest_Largest_Num(){
    if(start == NULL){
        printf("List is empty.\n");
        return;
    }
    struct node *st = start;
    int Largest = start -> data, Smallest = start -> data;
    while(st != NULL){
        if(st -> data > Largest)
            Largest = st -> data;
        if(st -> data < Smallest)
            Smallest = st -> data;
        st = st -> link;
    }
    printf("Smallest: %d, Largest: %d\n", Smallest, Largest);
}
// W.A.P to swap the First and Last Element of single linked list without swap the data.
void Swap_First_Last(){
    if(start == NULL || start->link == NULL){
        printf("Swap Not possible.\n");
        return;
    }
    struct node *prev = NULL, *last = start;
    // Find last node and its previous node
    while(last->link != NULL){
        prev = last;
        last = last->link;
    }
    // Swap nodes
    last->link = start->link;
    prev->link = start;
    start->link = NULL;
    start = last;
    printf("Swap Success.\n");
}
// W.A.P to move the Largest Element at the End of the single linked list.
void Largest_at_last(){
    if(start == NULL || start -> link == NULL){
        printf("Move Not possible.\n");
        return;
    }
    struct node *st = start, *prev = NULL;
    int Largest = start -> data;
    while(st -> link != NULL){
        if(st -> data > Largest)
            prev = st;
            Largest = st -> data;
        st = st -> link;
    }
    struct node *next = st -> link;
    prev -> link = next;
    st -> link = NULL;
}
// Main function of the programs -----
int main(){
    int n, key;
    int x, pos, AV, BV;
    printf("Enter the number of nodes to creat: ");
    scanf("%d", &n);
    create_List(n);
    while(1){
        printf("\n=== Single Linked List Menu ===\n");
        printf("Press 1  Insert at Beginning (InsertFirst)\n");
        printf("Press 2  Insert at End (InsertEnd)\n");
        printf("Press 3  Insert at Specific Position (InsertPosition)\n");
        printf("Press 4  Insert After a Value (InsertAfter)\n");
        printf("Press 5  Insert Before a Value (InsertBefore)\n");
        printf("Press 6  Search a Value\n");
        printf("Press 7  Count Nodes\n");
        printf("Press 8  Delete First Node\n");
        printf("Press 9  Delete Last Node\n");
        printf("Press 10 Delete Before a Value\n");
        printf("Press 11 Delete After a Value\n");
        printf("Press 12 Delete Specific Value\n");
        printf("Press 13 Display List\n");
        printf("Press 14 Find Largest or Smallest Number.\n");
        printf("Press 15 swap the First and Last Element.\n");
        printf("Press any other key Exit\n");
        
	    scanf("%d", &key);
	    switch(key){
	        case 1:
	            printf("Enter value to insert_first:");
	            scanf("%d", &x);
	            InsertFirst(x);
	            break;
	        case 2:
	            printf("Enter value to InsertEnd:");
	            scanf("%d",&x);
	            InsertEnd(x);
	            break;
	        case 3:
	            printf("Enter value to insert in position:");
	            scanf("%d", &x);
	            printf("Enter the Position -");
	            scanf("%d", &pos);
	            InsertPosition(x, pos);
	            break;
	        case 4:
	            printf("Enter value to insert");
	            scanf("%d", &x);
	            printf("Enter the after value to insert after.");
	            scanf("%d", &AV);
	            InsertAfter(x, AV);
	            break;
	        case 5:
	            printf("Enter value to insert");
	            scanf("%d", &x);
	            printf("Enter the after value to insert after.");
	            scanf("%d", &BV);
	            InsertBefore(x, BV);
	            break;
	        case 6:
	            printf("Enter value to search:");
	            scanf("%d", &x);
	            Search(x);
	            break;
	        case 7:
	            printf("Node count: %d\n", NodeCount());
	            break;
	        case 8:
	            printf("Delete first Element:");
	            DeleteFirst();
	            break;
	        case 9:
	            printf("Delete Last Element:");
	            DeleteLast_0();
	            break;
	        case 10:
	            printf("Enter value to delete Before Value- ");
	            scanf("%d", &x);
	            DeleteBefore(x);
	            break;
	        case 11:
	            printf("Enter value to delete After Value- ");
	            scanf("%d", &x);
	            DeleteAfter(x);
	            break;
	        case 12:
	            printf("enter value to Delete Specific Value:");
	            scanf("%d", &x);
	            DeleteSpecificValue(x);
	            break;
	        case 13:
	            printf("Your Linked list:\n");
	            Display_List();
	            break;
            case 14:
                Smallest_Largest_Num();
                break;
            case 15:
                Swap_First_Last();
                Display_List();
                break;
	        default:
	            printf("Exiting...\n");
	            exit(0);
	            break;
	    }
	}
}

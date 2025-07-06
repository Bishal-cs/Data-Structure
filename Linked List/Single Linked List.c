struct node {
    int data;
    struct node * link;
};
struct node * start = NULL;

// Insert First ----------------------
void InsertFirst(int value){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(start == NULL) {
        temp->link = NULL;
    }else if(start != NULL) {
        temp->link = start;
        start = temp;
    }else {
        temp->link = start;
        start = temp;
    }
}
// Insert Last -----------------------
void InsertEnd(int value){
    struct node * temp = (struct temp *)malloc(sizeof(struct node));
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
    struct node * temp = (struct temp *)malloc(sizeof(struct node));
    temp->data = value;
    if (start == NULL){
        temp -> link = NUll;
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
}
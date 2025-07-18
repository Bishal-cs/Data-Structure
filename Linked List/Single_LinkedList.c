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
            if(q -> data = beforeValue){
                p -> link = temp;
                temp -> link = q;
            }else{
                p = p -> link;
                q = q -> link;
            }
        }if(start -> data == beforeValue){
            temp -> link = start;
            temp -> link = start;
        }else{
            printf("Value %d not found in the list.\n", beforeValue);
        }
    }
}

// check the node number with value of the Position -------------------
void Search(int value){
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
void NodeCount(){
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
int DeleteLast(){
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
int DeleteLast(){
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
    if(start == NULL || start -> link = NULL || start -> data == value){
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
    int x = -1;
    struct node *p = start, *q = start -> link, *r = q ->link;
    if(start == NULL || start -> link == NULL){
        printf("There is No node");
    }
    else{
        while(r != NULL){
            if(p -> data == value){
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
    printf("Start --->");
    while(st != NULL){
        printf("%d --->",st);
        st = st -> link;
    }
    printf("NULL. !");
}
// Create New List from start ---------
void create_List(int n){
    int i, v;
    struct node *N = (struct node *)malloc(sizeof(struct node *));
    struct node *p;
    for(i = 1, i<=n, i++){
        printf("Enter value to create number of nodes: ");
        scanf("%d", &v);
        N -> data = v;
        N -> link = NULL;
        if(start == NULL){
            start = N;
        }
        else{
            p -> link = N;
        }
        p = N;
    }
}
// Main function of the programs -----

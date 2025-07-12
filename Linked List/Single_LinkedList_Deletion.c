struct node {
    int data;
    struct node * link;
};

struct node * start = NULL;

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
void DeleteBefore(int value){
    struct node *p = start, *q = start -> link;
    int x,
    if(start == NULL){
        printf("There is No node");
        x = -1;
    }
    else if (start -> link == NULL){
        printf("There are single node so cant delete!");
        x = -1;
    }
    else{
        struct node *temp = p;
        while(q -> link != NULL){
            if(q -> data == value){
                x = p -> data; 
                temp -> link = NULL;
                p = p -> link;
                q = q -> link;
                free(temp);
            }
            else{
                p = p -> link;
                q = q -> link;
            }
        } 
    }
    return x;
}
// delete after given value 
void DeleteAfter(int value){
    struct node *p = start, *q = start -> link;
    if(start == NULL){
        printf("There is No node");
    }
    else if (start -> link == NULL){
        printf("There are single node so cant delete!");
    }
    else{
        struct node *temp = q;
        while(q -> link != NULL){
            if(p -> data == value){.
                temp -> link = NULL;
                p = p -> link;
                q = q -> link;
                free(temp);
            }
            else{
                p = p -> link;
                q = q -> link;
            }
        } 
    }
}
// Delete Specific given value
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
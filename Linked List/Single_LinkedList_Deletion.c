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
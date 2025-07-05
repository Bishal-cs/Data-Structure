struct node {
    int data;
    struct node * link;
};
struct node * start = NULL;
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
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *link;
};
struct stack *top = NULL;

int is_Empty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(int value){
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if(temp == NULL){
        printf("Memory allocation failed! Stack Overflow.\n");
        return;
    }
    temp->data = value;
    temp->link = top;
    top = temp;
}

int POP(){
    if(is_Empty() == 1){
        return -1;
    }
    else{
        struct stack *p = top; 
        top = top -> link;
        int x = p -> data;
        p -> link = NULL;
        free(p);
        return x;
    }
}

int Peek(){
    if(top == NULL){
        printf("Stack Overflow !\n");
        return -1;
    }
    else{
        int x = top -> data;
        return x;
    }
}

void Display(){
    printf("Stack = ");
    if(is_Empty()){
        printf("TOP -> NULL\n");
    } else {
        struct stack *p = top;
        printf("TOP -> ");
        while(p != NULL){
            printf("%d -> ", p->data);
            p = p->link;
        }
        printf("NULL\n");
    }
}

void main(){
    int key, value;
    int maxOption = 15;
    while(1){
        printf("Press 1 to push.\n");
        printf("Press 2 to pop.\n");
        printf("Press 3 to peek.\n");
        printf("Press 4 to Display.\n");
        printf("Press Any key to Exit.\n --> ");
        scanf("%d", &key);
        if(key < 1 || key > maxOption) {
            printf("Wrong choice!\n");
            exit(0);
            break;
        }
        switch(key){
            case 1:
                printf("Enter Data to insert in stack: ");
                scanf("%d", &value);
                Push(value);
                break;
            case 2:
                if(POP() == -1){
                    return;
                }
                else{
                    printf("\nPOP success! the data is - %d", POP());
                    break;
                }
            case 3:
                if(Peek() == -1){
                    return;
                }
                else{
                    printf("Your Top data is - %d", Peek());
                    break;
                }
            case 4:
                Display();
                break;
            
        }
    }
}
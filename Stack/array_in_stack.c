#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;

// Is full function that check the stack is full or not ---
int is_Full(){
    if(top == MAX -1)
        return 1;
    else
        return 0;
}
// Is Empty function that check the stack is empty or not ---
int is_Empty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}
// Push function is used to push data in stack ---
void PUSH(int data){
    if(is_Full() == 1){
        printf("Stack Overflow !\n");
        return;
    }
    else{
        printf("The code is not rdy!!!!!!!");
        return;
    }
}
// Pop Function is used to free data in stack ---
int POP(){
    int y;
    if(is_Empty() == 1){
        printf("Stack Underflow !\n");
        return -1;
    }
    else{
        y = stack[top];
        top --;
    }
    return y;
}
// Peek Function is used to show the top of the element ---
int PEEK(){
    if(is_Empty() == 1){
        printf("Stack Underflow !\n");
        return -1;
    }
    return stack[top];
}
// Display function is used to Show the data in the stack ---
void Display(){
    if(is_Empty() == 1){
        printf("Stack Underflow !\n");
        return;
    }
    printf("Your data is\n");
    for(int i = 0; i <= top; i++){
        printf("%d", stack[i]);
    }
    printf("<- top");
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
                PUSH(value);
                break;
            case 2:
                if(POP() == -1){
                    return;
                }
                else{
                    printf("POP success! the data is - %d", POP());
                    break;
                }
            case 3:
                if(PEEK() == -1){
                    return;
                }
                else{
                    printf("Your Top data is - %d", PEEK());
                    break;
                }
            case 4:
                Display();
                break;
            
        }
    }
}
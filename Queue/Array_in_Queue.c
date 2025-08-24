#include<stdio.h>
#define MAX 5
int Queue[MAX];
int F = -1, R = -1;
// is full function ---
int is_Full(){
    if(R == MAX -1){
        return 1;
    }
    else{
        return 0;
    }
}

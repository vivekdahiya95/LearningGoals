/**
 * @file stack_.cpp
 * @brief this data structure is used in the LIFO format
 */

#include<stdio.h>

#define N 100

int top;
int stack[N];

void init(void){
    top=0;
}

int isEmpty(void){
    return (top==0);
}

int isFull(void){
    return (top==N);
}

int sPush(int value){
    if(isFull()){
        printf("Stack is full upto %d",N);
        return 0;
    }
     stack[top++]=value;
     return 1;
}

int sPop(int* value){
    if(isEmpty()){
        printf("stack is empty");
        return 0;
    }

    top--;
    *value=stack[top];

    return 1;
}

int main(int argc, char* argv[]){
    init();
    sPush(2);
    sPush(3);
    sPush(4);

    int value;
    sPop(&value);
    printf("%d",value);
    sPop(&value);
    printf("%d",value);
    sPop(&value);
    printf("%d",value);
    return 0;
}
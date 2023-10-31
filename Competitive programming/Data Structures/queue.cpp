/**
 * @file queue.cpp
 * @brief this is adding a new val at the front of the queue and taking it from the rear based on the first in first out principle
 */
#include<stdio.h>

#define N 100
int front;
int rear;
int container[N];

void init(void){
    rear=0;
    front=0;
}


int isEmpty(void)
{
    return (front==rear);
}

int isFull(void){
    if((front+1)%N==rear){
        return 1;
    }
    else 
        return 0;
}
 int enqueue(int val){
    if(isFull()){
        printf("this queue is full");
        return 0;
    }
    container[front]=val;
    front++;
    if(front==N){
        front=0;
    }
    return 1;
 }

int dequeue(int* val){
    if(isEmpty()){
        printf("container is empty");
        return 0;
    }
    *val=container[rear];
    rear+=1;
    if(rear==N){
        rear=0;
    }
    return 1;
}
    
int main(int argc,char* argv[]){
    init();
    enqueue(5);
    enqueue(6);
    enqueue(7);
    int val;
    dequeue(&val);
    printf("%d",val);
    dequeue(&val);
    printf("%d",val);
    dequeue(&val);
    printf("%d",val);
    return 0;
}



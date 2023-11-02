#include<stdio.h>

#define MAX 100

int arr[MAX];
int front;
int rear;
int size;

void init(int n){
    front=-1;
    rear=0;
    size=n;
}

bool isFull(){
    return ((front==0 && rear==size-1) ||(front==rear+1));
}

bool isEmpty(){
    return (front==-1);
}

void insertFront(int value){
    if(isFull()){
        printf("overflow");
    }
    if(front==-1){
        front=rear=0;
    }
    else if(front==0){
        front=size-1;
    }
    else{
        front=front-1;
    }
    arr[front]=value;
}

void insertRear(int value){
    if(isFull()){
        printf("overflow");
    }
    if(front==-1){
        front=rear=0;
    }
    else if(rear==size-1){
        rear=0;
    }
    else{
        rear=rear+1;
    }
    arr[rear]=value;
}

int getFront(){
    if(isEmpty()){
        printf("underflow");
        return -1;
    }
    return arr[front];
}

int getRear(){
    if(isEmpty()){
        printf("underflow");
        return -1;
    }
    return arr[rear];
}

void deleteFront(){
    if(isEmpty()){
        printf("underflow");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==size-1){
        front=0;
    }
    else{
        front=front+1;
    }
}

void deleteRear(){
    if(isEmpty()){
        printf("underflow");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=size-1;
    }
    else{
        rear=rear-1;
    }
}

int main(int argc,char* argv[]){
    init(10);
    insertFront(1);
    insertFront(2);
    insertFront(3);
    insertRear(4);
    insertRear(5);
    insertRear(6);
    for(int i=0;i<3;i++){
        int val1=0,val2=0;
        val1=getFront();
        deleteFront();
        val2=getRear();
        deleteRear();
        printf("%d %d\n",val1,val2);
    }
    return 0;

}
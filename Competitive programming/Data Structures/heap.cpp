/**
 * @file heap.cpp
 * @brief heap data structure
 * 
 */

#include<stdio.h>

#define N 100

int container[N];
int heapsize=0;

void init(void){
    heapsize=0;
    return;
}

int push(int value){
    //place it at the last position and keep pushing to the top of the heap
    if(heapsize+1>N){
        printf("heap has no space left");
        return 0;
    }
    container[heapsize]=value;
    //push this value to it's correct value
    int temp=heapsize;
    while(temp>0 && container[temp]<container[(temp-1)/2]){
        //if above holds then swap the two values
        int swapper=container[(temp-1)/2];
        container[(temp-1)/2]=container[temp];
        container[temp]=swapper;
        temp=(temp-1)/2;
    }
    heapsize+=1;
    return 1;
}
int pop(int *val){
    if(heapsize<0){
        printf("container is empty!!");
        return 0;
    }
    //to remove the top element replace the top element with infinity and move it downwards based on comparisons
    *val=container[0];
    heapsize-=1;
    
    container[0]=container[heapsize];
    int temp=0;
    while(temp*2+1<heapsize){
        int child;
        if(temp*2+2==heapsize){
            child=temp*2+1;
        }
        else{
            child=container[temp*2+1]<container[temp*2+2]?temp*2+1:temp*2+2;
        }
        if(container[temp]<container[child]){
            break;
        }
        //swap the two values;
        int swapper=container[temp];
        container[temp]=container[child];
        container[child=swapper];
        temp=child;
    }
    return 1;

}

int main(int argc,char* argv[]){
    init();
    for(int i=0;i<100;i++)
        push(i);
    printf("%d",heapsize);
    int val;
    pop(&val);
    printf("%d",val);
    pop(&val);
    printf("%d",val);
    pop(&val);
    printf("%d",val);
    return 0;

}
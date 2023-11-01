#include<stdio.h>
#include<malloc.h>


typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* create_node(int data){
    node* temp_node=(node *)malloc(sizeof(node));
    temp_node->data=data;
    temp_node->next=nullptr;
    temp_node->prev=nullptr;
    return temp_node;
}

node* insert_(node* head,node* new_node){
    node* temp=head->next;
    
    head->next=new_node;
    new_node->next=temp;
    new_node->prev=head;

    if(temp!=nullptr){
        temp->prev=new_node;
    }
    return new_node;
}

int erase_(node* head,int data){
    node* temp=head->next;
    int ans=0;

    while(temp!=nullptr){
        if(temp->data==data){
            node* prev=temp->prev;
            node* next=temp->next;
            node* curr=temp;
            temp=temp->next;

            prev->next=next;
            if(next!=nullptr){
                next->prev=prev;
            }
            free(curr);
            ans++;
        }
        else{
            temp=temp->next;
        }
    }
    return ans;
}


int main(int argc,char* argv[]){
    //create a head node assuming data is always >0
    node* head=create_node(-1);
    for(int i=0;i<5;i++){
        node* temp=create_node(i);
        insert_(head,temp);
    }
    erase_(head,3);
    node* temp=head->next;
    while(temp!=nullptr){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return 0;
}
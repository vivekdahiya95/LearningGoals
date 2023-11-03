#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    Node *left,*right;
    int key;
    int val;
}Node;

Node* newNode(int k,int v){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->key=k;
    temp->val=v;
    temp->left=temp->right=nullptr;
    return temp;
}

Node* current;

Node* addNode(Node* node,int key,int val){
    if(node==nullptr) return newNode(key,val);
    if(key<node->key){
        node->left=addNode(node->left,key,val);
    }
    else if(key>node->key){
        node->right=addNode(node->right,key,val);
    }
    else 
        node->val=val;
    return node;
}

void add(int key,int val){
    current=addNode(current,key,val);
}

int findNode(Node* node,int key){
    if(node!=nullptr){
        if(key==node->key) return node->val;
        int ret=-1;
        ret=findNode(node->left,key);
        if(ret!=-1) return ret;
        ret=findNode(node->right,key);
        if(ret!=-1) return ret;
    }
    return -1;
}

bool find(int key){
    if(current==nullptr) return false;
    int ret=findNode(current,key);
    if(ret!=-1) return true;
    return false;
}

int get(int key){
    return findNode(current,key);
}

Node* minValueNode(Node* temp){
    Node* curr=temp;

    while(curr->left){
        curr=curr->left;
    }
    return curr;
}

Node* remove(Node* node,int key){
    if(node==nullptr) return node;
    if(key<node->key){
        node->left=remove(node->left,key);
    }
    if(key>node->key){
        node->right=remove(node->right,key);
    }
    else{
        if(node->left==nullptr){
            Node* temp=node->right;
            free(node);
            return temp;
        }
        else if(node->right==nullptr){
            Node* temp=node->left;
            free(node);
            return temp;
        }

        Node* temp=minValueNode(node->right);
        node->key=temp->key;
        node->val=temp->val;
        node->right=remove(node->right,temp->key);
    }
    return node;
}


void remove(int key){
    remove(current,key);
}

int main(int argc,char* argv[]){
    add(1,2);
    add(2,3);
    add(4,5);
    printf("%d\n",get(2));
    remove(2);
    printf("%d",get(2));
    return 0;
}


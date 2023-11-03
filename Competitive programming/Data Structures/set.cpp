#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int key;
    Node* left,* right;
}Node;

Node* newNode(int value){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->key=value;
    temp->left=temp->right=nullptr;
    return temp;
};

Node* current;

Node* addNode(Node* node,int key){
    if(node==nullptr) return newNode(key);
    if(key<node->key){
        node->left=addNode(node->left,key);
    }
    else if(key>node->key){
        node->right=addNode(node->right,key);
    }
    return node;
}

void add(int key){
    current=addNode(current,key);
}

bool findNode(Node* node,int key){
    if(node!=nullptr){
        if(key==node->key) return true;
        return (key==node->key || findNode(node->left,key)|| findNode(node->right,key));
    }
    return false;
}

bool contains(int key){
    return findNode(current,key);
}

void printAll(Node* node){
    if(node!=nullptr){
        printAll(node->left);
        printf("%d ",node->key);
        printAll(node->right);
    }
}


void printAll(){
    printAll(current);
}


Node* minValueNode(Node* node){
    Node* temp=node;

    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}

Node* removeNode(Node* node,int key){
    if(node==nullptr){
        return node;
    }
    if(key<node->key){
        node->left=removeNode(node->left,key);
    }
    else if(node->key<key){
        node->right=removeNode(node->right,key);
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
        node->right=removeNode(node->right,temp->key);
    }
    return node;
}

void remove(int key){
    current=removeNode(current,key);
}

int main(int argc,char* argv[]){
    add(1);
    add(2);
    add(3);
    add(4);
    printAll();
    remove(1);
    printAll();
    return 0;
}
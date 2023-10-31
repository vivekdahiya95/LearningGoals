#include<stdio.h>

#define maxNodes 10000
#define maxChild 2

typedef struct{
    int parent;
    int child[maxChild];
}Node;

Node tree[maxNodes];

void init(void){
    int i,j;
    for(i=0;i<=maxNodes;i++){
        tree[i].parent=-1;
        for(j=0;j<maxChild;j++){
            tree[i].child[j]=-1;
        }
    }
}

void addChild(int parent,int child){
    int i;
    for(i=0;i<maxChild;i++){
        if(tree[parent].child[i]==-1){
            break;
        }
    }
    tree[parent].child[i]=child;
    tree[child].parent=parent;
}

int getRoot(void){
    int i;
    for(i=0;i<maxNodes;i++){
        if(tree[i].parent==-1){
            return i;
        }
    }
    return -1;
}

void operationPreorder(int root){
    int i;
    int child;
    printf("%d ",root);
    for(i=0;i<maxChild;i++){
        child=tree[root].child[i];
        if(child!=-1){
            operationPreorder(child);
        }
    }
}


int main(int argc,char* argv[]){
    init();
    addChild(0,1);
    addChild(0,2);
    addChild(1,3);
    addChild(1,4);
    printf("%d %d %d",tree[0].child[0],tree[0].child[1],tree[0].parent);
    printf("\n");
    printf("%d %d %d",tree[1].child[0],tree[1].child[1],tree[1].parent);
    printf("\n");
    printf("%d %d %d",tree[2].child[0],tree[2].child[1],tree[2].parent);
    printf("\n");
    printf("%d %d %d",tree[3].child[0],tree[3].child[1],tree[3].parent);
    printf("\n");
    printf("%d %d %d",tree[4].child[0],tree[4].child[1],tree[4].parent);
    printf("\n");
    printf("%d %d %d",tree[5].child[0],tree[5].child[1],tree[5].parent);
    printf("\n");
    operationPreorder(0);
}
#include<stdio.h>
#include<memory.h>
#include<malloc.h>

typedef struct adjlistNode{
    int vertex;
    adjlistNode* next;
}AdjlistNode;

typedef struct{
    int num_members;
    AdjlistNode* head;
    AdjlistNode* tail;
}AdjList;

typedef struct{
    int numVertices;
    AdjList* adjListArr;
}Graph;

AdjlistNode* createNode(int v){
    AdjlistNode* newNode=(AdjlistNode*)malloc(sizeof(AdjlistNode));
    newNode->vertex=v;
    newNode->next=nullptr;

    return newNode;
}

Graph* createGraph(int n){
    printf("CreateGraph\n");
    Graph* graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=n;
    graph->adjListArr=(AdjList*)malloc(n*sizeof(AdjList));

    for(int i=0;i<n;i++){
        graph->adjListArr[i].head=graph->adjListArr[i].tail=nullptr;
        graph->adjListArr[i].num_members=0;
    }
    return graph;
}

void destroyGraph(Graph* graph){
    if(graph){
        if(graph->adjListArr){
            for(int v=0;v<graph->numVertices;v++){
                AdjlistNode* tempNode=graph->adjListArr[v].head;
                while(tempNode){
                    adjlistNode* temp=tempNode;
                    tempNode=tempNode->next;
                    free(temp);
                }
            }
            free(graph->adjListArr);
        }
        free(graph);
    }
}

void addEdge(Graph* graph,int src, int dest){
    printf("addEdge\n");
    AdjlistNode* newNode=createNode(dest);
    if(graph->adjListArr[src].tail!=nullptr){
        graph->adjListArr[src].tail->next=newNode;
        graph->adjListArr[src].tail=newNode;
    }
    else{
        graph->adjListArr[src].head=graph->adjListArr[src].tail=newNode;
    }
    graph->adjListArr[src].num_members++;

    newNode=createNode(src);
    if(graph->adjListArr[dest].tail!=nullptr){
        graph->adjListArr[dest].tail->next=newNode;
        graph->adjListArr[dest].tail=newNode;
    }
    else{
        graph->adjListArr[dest].head=graph->adjListArr[dest].tail=newNode;
    }
    graph->adjListArr[dest].num_members++;

}

void display(Graph* graph,int i){
    AdjlistNode * tempNode=graph->adjListArr[i].head;
    while(tempNode){
        printf("%d\n",tempNode->vertex);
        tempNode=tempNode->next;
    }
}
int main(int argc,char* argv[]){
    // int v;
    // scanf("%d",&v);
    
    printf("I am here!!\n");
    Graph* questiongraph= createGraph(6);
    addEdge(questiongraph,0,1);
    addEdge(questiongraph,0,2);
    addEdge(questiongraph,0,3);
    addEdge(questiongraph,0,4);
    display(questiongraph,0);
}




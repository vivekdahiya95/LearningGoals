#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

vector<int> graph[N];
int parent[N];
int depth[N];

void dfs(int node,int par){
    parent[node]=par;
    depth[node]=depth[par]+1;//take care here because how you are declaring the root matters 
    for(auto temp:graph[node]){
        if(temp!=par){
            dfs(temp,node);
        }
    }
    return;
}

int LCA(int node1,int node2){
    //base case if node1 is equal to node2
    if(node1==node2) return node1;
    if(depth[node1]<depth[node2]){//we will write the loops and code such that the node1 has higher depth
        swap(node1,node2);
    }
    int diff=depth[node1]-depth[node2];
    while(diff){
        node1=parent[node1];
    }
    while(node1!=node2){
        node1=parent[node1];
        node2=parent[node2];
    }
    return node1;
}

int main(int argc,char* argv[]){
    return 0;
}
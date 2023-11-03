#include<bits/stdc++.h>

using namespace std;

const int N=1007;
vector<int> graph[N];
int parent[N];

void dfs_tree(int node,int par){
    parent[node]=par;
    for(auto temp:graph[node]){
        if(temp!=par){
            dfs_tree(temp,node);
        }
    }
}

int  main(int argc,char* argv[]){
    return 0;
}

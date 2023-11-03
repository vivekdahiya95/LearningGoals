#include<bits/stdc++.h>

using namespace std;

const int N=1007;
vector<int> graph[];
int parent[N];
vector<int> visited(N,-1);


void backedge(int node,int par){
    parent[node]=par;
    visited[node]=1;
    for(auto temp:graph[node]){
        if(temp!=par){
            if(visited[temp]!=-1){
                cout<<"backedge detected\n";
                return;
            }
            backedge(temp,node);
        }
    }
}

int main(int argc,char* argv[]){
    return 0;
}
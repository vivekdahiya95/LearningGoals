#include<bits/stdc++.h>
using namespace std;

const int N=100007;
vector<int> graph[N],order;
int visited[N];

void dfs(int node,int par){
    visited[node]=1;
    for(auto temp:graph[node]){
        if(!visited[temp]){
            dfs(temp,node);
        }
    }
    order.push_back(node);
    return;
}

int main(int argc,char* argv[]){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,0);
        }
    }
    reverse(order.begin(),order.end());
    for(auto a:order){
        cout<<a<<" ";
    }
    return 0;
}
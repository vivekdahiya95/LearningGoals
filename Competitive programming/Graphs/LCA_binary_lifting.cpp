#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;

vector<int> graph[N];
int parent[N],depth[N];
int sparse_table[N][12];
// it contains 2^n the parent of the i the row member(node)
// parent[n][m]**** nth nodes' mth 2^m parent
//**********  parent[n][m]=parent[parent[n][m-1]][m-1]    *********** read it again and again

void dfs(int node,int par){
    depth[node]=depth[par]+1;
    sparse_table[node][0]=par;
    for(int i=1;i<12;i++){
        sparse_table[node][i]=sparse_table[sparse_table[node][i-1]][i-1];//be careful and try to visualize the top row of this table we will be building
        //incrementaly here and top row considering it is the root will have only the parent we will start counding from node 1
        //the sparse_table[node][i-1] should spit out 0 initially which should all be filled with 0
    }
    for(auto temp:graph[node]){
        dfs(temp,node);
    }
    return;
}

int LCA(int node1,int node2){
    if(node1==node2) return node1;
    if(depth[node1]<depth[node2]) swap(node1,node2);
    int diff=depth[node1]-depth[node2];
    for(int i=32;i>0;i--){
        if(diff>>i&1){
            node1=sparse_table[node1][i];
        }
    }
    for(int i=11;i>=0;i--){
        if(sparse_table[node1][i]!=sparse_table[node2][i]){
            node1=sparse_table[node1][i];
            node2=sparse_table[node2][i];
        }
    }
    return sparse_table[node1][0];
}

int main(int argc,char* argv[]){
    return 0;
}

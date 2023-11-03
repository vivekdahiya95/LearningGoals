#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> l;
    public:
    Graph(int v){
        this->v=v;
    }

    void add_edge(int u,int v){
        l.push_back({u,v});
    }

    int find_set(int node,int parent[]){
        if(parent[node]==-1) return node;
        return parent[node]=find_set(parent[node],parent);
    }

    int union_set(int node1,int node2,int parent[],int rank[]){
        int s1=find_set(node1,parent);
        int s2=find_set(node2,parent);

        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    bool contain_cycle(){
        int *parent=new int[v];
        int *rank=new int[v];

        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto edge:l){
            int node1=edge.first;
            int node2=edge.second;

            int s1=find_set(node1,parent);
            int s2=find_set(node2,parent);
            
            if(s1!=s2){
                union_set(s1,s2,parent,rank);
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(int argc,char* argv[]){
    return 0;
}
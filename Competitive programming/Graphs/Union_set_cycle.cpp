#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> l;

    public:
    Graph(int v){
        this->v=v;
    }

    void addEdge(int u,int v){
        l.push_back({u,v});
    }

    int find_set(int node,int parent[]){
        if(parent[node]==-1){
            return node;
        }
        return find_set(parent[node],parent);
    }

    void union_set(int u,int v,int parent[]){
        int par1=find_set(u,parent);
        int par2=find_set(v,parent);
        if(par1!=par2){
            parent[par2]=par1;
        }
    }
    bool contains_cycle(){
        int *parent=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
        }

        for(auto edge:l){
            int node1=edge.first;
            int node2=edge.second;

            int s1=find_set(node1,parent);
            int s2=find_set(node2,parent);

            if(s1!=s2){
                union_set(s1,s2,parent);
            }
            else{
                return true;
            }
        }
        delete[] parent;
        return false;
    }

};

int main(int argc,char* argv[]){
    return 0;
}
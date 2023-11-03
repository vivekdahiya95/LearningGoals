#include<bits/stdc++.h>
using namespace std;


class DSU{
    int *parent;
    int *rank;

    public:
    DSU(int v){
        parent=new int[v];
        rank=new int [v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }

    int find_set(int node){
        if(parent[node]==-1) return node;
        return parent[node]=find_set(parent[node]);
    }

    int union_set(int node1,int node2){
        int s1=find_set(node1);
        int s2=find_set(node2);

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
};

class Graph{
    int v;
    vector<vector<int>> graph;
    public:
    Graph(int v){
        this->v=v;
    }

    void addEdge(int u,int v,int w){
        graph.push_back({w,u,v});
    }

    int KruskalMST(){
        sort(graph.begin(),graph.end());
        DSU s(v);
        int ans=0;
        for(auto temp:graph){
            int wt=temp[0];
            int start=temp[1];
            int end=temp[2];
            if(s.find_set(start)!=s.find_set(end)){
                s.union_set(start,end);
                ans+=wt;
            }
        }
        return ans;
    }
};
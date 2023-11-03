#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *graph;

    Graph(int v){
        this->v;
        graph=new list<pair<int,int>>[v];
    }

    void addEdge(int u,int v,int w,bool undir=true){
        graph[u].push_back({w,v});
        if(undir){
            graph[v].push_back({w,u});
        }
        return;
    }

    int dijkstra(int src, int dest){
        vector<int> dist(v,INT_MAX);
        set<pair<int,int>> s;
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty()){
            auto it=s.begin();
            int wt=it->first;
            int temp=it->second;
            s.erase(it);
            for(auto edge:graph[temp]){
                int to=edge.second;
                int tempwt=edge.first;
                if(wt+tempwt<dist[to]){
                    auto f=s.find({dist[to],to});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[to]=wt+tempwt;
                    s.insert({dist[to],to});
                }
            }
        }
        return dist[dest];
    }
};


int main(int argc,char* argv[]){
    return 0;
}
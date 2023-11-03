#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<pair<int,int>> *adj;
    public:
    Graph(int v){
        this->v=v;
        adj=new vector<pair<int,int>>[v];
    }
    void addEdge(int x,int y,int w){
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int prims(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        bool *vis=new bool[v]{0};

        int ans=0;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> temp=q.top();
            q.pop();
            int to=temp.second;
            int weight=temp.first;

            if(vis[to]){
                continue;
            }
            ans+=weight;
            vis[to]=1;

            for(auto x:adj[to]){
                int y=x.first;
                int wt=x.second;
                if(!vis[y]){
                    cout<<y<<" "<<wt<<"\n";
                    q.push({wt,y});
                }
            }
        }
        return ans;
    }

};

int main(int argc,char* argv[]){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,3,4);
    cout<<g.prims();
    return 0;
}
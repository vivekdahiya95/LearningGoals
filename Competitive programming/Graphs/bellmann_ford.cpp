//bellman ford algorithm(Single source shortest path algorithm)
/*
Has more time complexity than Dijkastras because it is able to handle negative edges also
time complexity->O(E)#best case
O(VE) average case
O(E(V^2)) in the cases where the graph is disconnected
Space complexity-> O(V) auxiliary space

*/

#include<bits/stdc++.h>
using namespace std;


vector<int> bellman_ford(int v, int src,vector<vector<int>> edges){
    //create a distances array
    vector<int> distances(v+1,INT_MAX);
    distances[src]=0;

    //relax all the edges v-1 times
    for(int i=0;i<v-1;i++){
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(distances[u]!=INT_MAX && distances[v]>distances[u]+wt){
                distances[v]=distances[u]+wt;
            }
        }
    }
    //now run one more update and if you are able to make changes to the distances array then you have a negative cycle in your graph

    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        if(distances[u]!=INT_MAX && distances[v]>distances[u]+wt){
            //then there is a negative cycle
            cout<<"there is a negative cycle\n";
            return {};
        }
    }
    return distances;
}
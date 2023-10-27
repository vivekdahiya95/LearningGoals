//floyd warshall algorithm
/*
Time complexity->O(n^3)
Space complexity->O(n^2)

*/
#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> graph){
    /*
    just think of the graph as a 4*4 matrix at first
    {
        {0,INF,-2,INF},
        {4,0,3,INF},
        {INF,INF,0,2},
        {INF,-1,INF,0}
    }
    
    */
   vector<vector<int>> distances(graph);
   int v=graph.size();// gives the number of nodes in the graph

   //now we run the algorithm in phases
   // in the kth phase we just include all the nodes from 1...k in the calculation of paths from one point to another

   for(int k=0;k<v;k++){
    //now iterate over the whole 2d matrix
        for(int i=0; i<v;i++){
            for(int j=0;j<v;j++){
                if(distances[i][j]>distances[i][k]+distances[k][j]){
                    distances[i][j]=distances[i][k]+distances[k][j];
                }
            }
        }
   }
   return distances;

}
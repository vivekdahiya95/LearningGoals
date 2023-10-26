//Segment tree without lazy propogation
#include<bits/stdc++.h>
using namespace std;

struct segTree{
    int n;
    vector<int> segt;

    void init(int n){
        this->n=n;
        segt.resize(4*n,0);// we need max 4 times the number of nodes to store the seg Tree
    }

    void build(int start,int end,int node,vector<int>& val){
        if(start==end){
            segt[node]=val[start];
        }
        int mid=(start+end)/2;
        build(start,mid,2*node+1,val);
        build(mid+1,end,2*node+2,val);
        segt[node]=segt[2*node+1]+segt[2*node+2]; // here you can perform any operation related to the information you want to process
        return;
    }
    void update(int start,int end, int index,int val, int node){
        if(start==end){
            segt[node]=val;
            return;
        }
        int mid=(start+end)/2;
        if(index<=mid){
            update(start,mid,index,val,2*node+1);
        }
        else{
            update(mid+1,end,index,val,2*node+2);
        }
        segt[node]=segt[2*node+1]+segt[2*node+2];
        return;
    }
    int query(int start,int end, int l,int r,int node){
        //lies completely outside and inside cases
        if(start>r or end<l) return 0; //here start and end represent the pointer in the segt and l and r are the query pointers
        if(start>=l and end<=r){
            return segt[node];
        }
        int mid=(start+end)/2;
        int q1=query(start,mid,l,r,2*node+1);
        int q2=query(mid+1,end,l,r,2*node+2);
        return q1+q2;
    }

};
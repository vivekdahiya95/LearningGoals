//Segment tree without lazy propogation
#include<bits/stdc++.h>
using namespace std;

struct lazyTree{
    int n;
    vector<int> segt,lazyt;

    void init(int n){
        this->n=n;
        segt.resize(4*n,0);// we need max 4 times the number of nodes to store the seg Tree
        lazyt.resize(4*n,0);
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
    void update(int start,int end, int l,int r,int val, int node)// star point of lazyt is that we can update a large number of values in one go
    {
        //lies completely outside
        if(start>r or end<l) return;
        //update the lazy tree part
        if(lazyt[node]!=0){
            segt[node]+=lazyt[node]*(end-start+1);
            if(start!=end){
                lazyt[2*node+1]+=lazyt[node];
                lazyt[2*node+2]+=lazyt[node];
            }
            lazyt[node]=0;
        }
        //complete overlap
        if(start>=l and end<=r){
            segt[node]+=(end-start+1)*val;
            if(start!=end){
                lazyt[2*node+1]+=(end-start+1)*val;
                lazyt[2*node+2]+=(end-start+1)*val;
            }
            return;
        }

        int mid=(start+end)/2;
        update(start,mid,l,r,val,2*node+1);
        update(mid+1,end,l,r,val,2*node+2);
        segt[node]=segt[2*node+1]+segt[2*node+2];
        return;
    }
    int query(int start,int end, int l,int r,int node){
        //lies completely outside
        if(start>r or end<l) return 0; //here start and end represent the pointer in the segt and l and r are the query pointers
        //since you have a lazy tree now and you need to go down from here first update the segt based on the lazyt updates
        if(lazyt[node]!=0){
            //we have to update the current node based on lazyt and we are also updating based on how many values are contributing towards that
            segt[node]+=lazyt[node]*(end-start+1);
            if(start!=end)//we are not at leaf nodes
            {
                lazyt[2*node+1]+=lazyt[node];
                lazyt[2*node+2]+=lazyt[node];
            }
            lazyt[node]=0;
        }
        if(start>=l and end<=r){
            return segt[node];
        }
        int mid=(start+end)/2;
        int q1=query(start,mid,l,r,2*node+1);
        int q2=query(mid+1,end,l,r,2*node+2);
        return q1+q2;
    }

};
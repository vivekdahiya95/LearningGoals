/*

0/1 knapsack problem
either you include it or not and you have to optimize the profit

*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int knapsack_0_1(int val[],int wt[],int bagWt,int n){
    //base case
    if(n==0 || bagWt==0){
        return 0;
    }

    if(wt[n-1]<=bagWt){
        return max(val[n-1]+knapsack_0_1(val,wt,bagWt-wt[n-1],n-1),knapsack_0_1(val,wt,bagWt,n-1));
    }
    else if(wt[n-1]>bagWt)
        return knapsack_0_1(val,wt,bagWt,n-1);

}

// dynamic programming solution
int static dp[10007][10007];
// I am considering that in the main you have initilized the dp to -1 using memset or any other method
int knapsack_0_1_dp(int wt[],int val[],int bagWt,int n){
    if(n==0 or bagWt==0) return 0;
    //here we have two variables which are constantly changing that is bagWt and n so we will condition on them to make the  dp solution
    if (dp[bagWt][n]!=-1) return dp[bagWt][n];
    if(wt[n-1]<=bagWt){
        return dp[bagWt][n]=max(knapsack_0_1_dp(wt,val,bagWt-wt[n-1],n-1),knapsack_0_1_dp(wt,val,bagWt,n-1));
    }
    else if(wt[n-1]>bagWt){
         return dp[bagWt][n]=knapsack_0_1_dp(wt,val,bagWt-wt[n-1],n-1);
    }
}
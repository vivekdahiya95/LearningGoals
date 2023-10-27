/**
 * @file rod_cutting_problem.cpp
 * @brief Rod cutting problem
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int dp[10005][10005];
//remember to reset the dp arr in the main everytime you call cutRod
int cutRod(int prices[],int len){
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len;j++){
            
            if(i==0 or j==0) dp[i][j]=0;

            else{
                if(i==1){//we are only allowing 1 len cuts in the rod
                    dp[i][j]=j*prices[i-1];
                }
                else{
                    if(i>j){//here we are trying to cut the rod more than its length which is not possible
                        dp[i][j]=dp[i-1][j];
                    }
                    else{//we make a cut of len i and check if it is the most optimal way of cutting
                        dp[i][j]=max(prices[i-1]+dp[i][j-i],dp[i-1][j]);
                    }
                }
            }

        }
    }
    return dp[len][len];
}
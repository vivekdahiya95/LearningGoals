/**
 * @file unbounded_knapsack.cpp
 * @brief given an aray of possible coin denominations you can use and each denomination you can use any number of times
 * return if you can make the target with these denominations and what is the minimum number of those denominations required
 * While building the solution you are just adding to the current possible value the current denomination and comparing with the minimum number
 * of demominations that made that possible

 * 
 */

#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int target){
    vector<int> dp(target+1,target+1);
    dp[0]=0;
    for(const int coin: coins){
        for(int i=coin;i<=target;i++){
            dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    return dp[target]==target+1?-1:dp[target];

}
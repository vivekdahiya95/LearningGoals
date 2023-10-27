/**
 * @file coin_change_ways.cpp
 * @brief number of ways with the given coins you can make the target achieve
 * solution->
 * dp[i+coin]=dp[i+coin]+dp[i]
 */

#include<bits/stdc++.h>
using namespace std;

int coin_change_ways(int amount,vector<int>& coins){
    vector<int> dp(amount+1,0);
    dp[0]=1;

    for(const int coin:coins){
        for(int i=0;i<=amount-coin;i++){
            dp[i+coin]+=dp[i];
        }
    }
    return dp[amount];
}
/**
 * @file minimum_nuber_of_coins.cpp
 * @brief minimum number of ways with the given coins you can make the target achieve
 * solution->
 * dp[i][j]=min(dp[i][j],dp[i][j-coin_i]+1)
 */

#include<bits/stdc++.h>
using namespace std;

int minimum_number_of_coins(int amount,vector<int>& coins){
    vector<int> dp(amount+1,INT_MAX);
    dp[0]=0;

    for(const int coin:coins){
        for(int i=coin;i<=amount;i++){
            dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    return dp[amount]==INT_MAX?-1:dp[amount];
}
/**
 * @file ShortestCommonSupersequence.cpp
 * @brief 
 */

#include<bits/stdc++.h>
using namespace std;
string shorotestCommonSupersequence(string str1,string str2){
    int n=str1.length();
    int m=str2.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=str2[i-1]==str1[j-1]?dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
        }
    }

    deque<char> ans;
    while(n||m){
        char c;
        if(n==0) c=str2[--m];
        else if(m==0) c=str1[--n];
        else if(str1[n-1]==str2[m-1]) c=str1[--n];
        else if(dp[m-1][n]==dp[n][m]) c=str2[--m];
        else if(dp[m][n-1]==dp[n][m]) c=str1[--n];
        ans.push_back(c);
    }
    return {begin(ans),end(ans)};
} 
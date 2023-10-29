/**
 * @file LongestRepeatingSubsequence.cpp
 * @brief Given a string, find the length of the longest repeating subsequence, such that the two subsequences don’t have same string character at the same * * position
 */
#include<bits/stdc++.h>
using namespace std;
int LongestRepeatingSubsequence(string str1,string str2){
    int n=str1.length();
    int m=str2.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(str2[i-1]==str1[j-1] && i!=j)?dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];    
}

int main()
{
    return 0;
}
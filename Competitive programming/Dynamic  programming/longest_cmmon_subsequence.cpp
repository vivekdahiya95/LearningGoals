/**
 * @file longest_cmmon_subsequence.cpp
 * @brief logic
 * if str1[n-1]==str2[m-1]
 * return 1+ LCS(str1,str2,n-1,m-1)
 * 
 * else 
 * return max(LCS(str1,str2,n-1,m),LCS(str1,str2,n,m-1))
 *
 */

#include<bits/stdc++.h>
using namespace std;

int LCSHelper(string str1,string str2,int n,int m){
    //since we only need the prvious row and the current row for all the calculations we won't maintain matrix here
    vector<int> dp1(n+1,0);
    vector<int> dp2(n+1,0);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(str1[j]==str2[i]){
                dp2[j+1]=dp1[j]+1;
            }
            else{
                dp2[j+1]=max(dp1[j+1],dp1[j]);
            }
        }
        swap(dp1,dp2);
    }
    return dp1[n];

}

int LCS(string str1,string str2){
    if(str1.length()<str2.length())
        swap(str1,str2);
    int n=str1.length();
    int m=str2.length();
    return LCSHelper(str1,str2,n,m);
}
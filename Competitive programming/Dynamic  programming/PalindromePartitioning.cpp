/**
 * @file PalindromePartitioning.cpp
 * @brief Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


dp[i] := ans of str[0:i]
dp[j] = { x + str[i:len] for x in dp[i] }, 0 <= i < len

Time complexity: O(2^n)
Space complexity: O(2^n)
 */

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s){
    const int n=s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
        return true;
    }
}

class Solution{
    public:
    vector<vector<string>> partition(string s){
        int n=s.length();
        vector<vector<vector<string>>> dp(n+1);
        for(int len=1;len<=n;++len){
            for(int i=0;i<len;i++){
                string right=s.substr(i,len-i);
                if(!isPalindrome(right)) continue;
                if(i==0){
                    dp[len].push_back({right});
                }
                for(const auto& p:dp[i]){
                    dp[len].push_back(p);
                    dp[len].back().push_back(right);
                }
            }
        }
        return dp[n];
    }
};
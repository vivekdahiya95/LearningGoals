/**
 * @file eggDropping.cpp
 * @brief leetcode 887
 * 
 * 
 * 
dp[k][n] := min number of moves to test n floors with k eggs.

Base cases:

dp[0][n] = 0 # no eggs left.
dp[1][n] = n  # one egg, need to test every floor.

Transition:

dp[k][n] = min(1 + max(dp[k][i – 1], dp[k – 1][n – i])) 1 <= i <= n

Time complexity: O(k*n^2)

Space complexity: O(k*n)
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int superEggDrop(int K, int N) {    
    m_ = vector<vector<int>>(K + 1, vector<int>(N + 1, INT_MIN));
    return dp(K, N);
  }
private:
  // m[i][j] := min moves of i eggs and j floors
  vector<vector<int>> m_;
  
  int dp(int k, int n) {
    if (k <= 0) return 0;
    if (k == 1) return n;
    if (n <= 1) return n;
    if (m_[k][n] != INT_MIN) return m_[k][n];
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
      ans = min(ans, 1 + max(dp(k - 1, i - 1),   // broken at floor i, need to test i - 1 floors using k - 1 eggs.
                             dp(k,     n - i))); // unbroken at floor i, need to test n - i floors using k eggs. 
    return m_[k][n] = ans;
  }
};
/**
 * @file scrambled_string.cpp
 * @brief hard 87 on leetcode
 * 
 */

#include<bits/stdc++.h>
using namespace std;


/*
points for solving the question

1-> s1 and s2 should have the same length
2-> s1 and s2 should have the same characters
3-> if we cut s1 at the indes i then string s2 also gets cut at the same index from back because we are comparing left to right and right to left
4-> check recursively if the left part of the string is scrambled string of right part of s2 and vice versa



Solution: Recursion

isScramble(s1, s2)
if s1 == s2: return true
if sorted(s1) != sroted(s2): return false
We try all possible partitions:

    s1[0:l] v.s s2[0:l] && s1[l:] vs s2[l:]
    s1[0:l] vs s2[L-l:l] && s1[l:] vs s2[0:L-l]

Time complexity: O(n^5)
Space complexity: O(n^4)


********************************* read about string_view properly*************************************
*/

unordered_map<string,int> mp;
class Solution {
public:
  bool isScramble(string_view s1, string_view s2) {    
    const int l = s1.length();        
    if (s1 == s2) return true;
    if (freq(s1) != freq(s2)) return false;
    for (int i = 1; i < l; ++i)
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) 
          && isScramble(s1.substr(i), s2.substr(i)) 
          || isScramble(s1.substr(0, i), s2.substr(l - i, i))
          && isScramble(s1.substr(i), s2.substr(0, l - i)))
        return true;
    return false;
  }
private:
  vector<int> freq(string_view s) {
    vector<int> f(26);
    for (char c : s) ++f[c - 'a'];
    return f;
  }
};
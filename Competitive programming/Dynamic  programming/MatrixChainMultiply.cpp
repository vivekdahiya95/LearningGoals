/**
 * @file MatrixChainMultiply.cpp
 * @brief You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.Return the maximum coins you can collect by bursting the balloons wisely.
 */

//note instead of solving the original matrix multiply problem here we are solving a variation of the same porblem from leetcode
// termed as ***************burst ballons**********

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int maxCoins(vector<int>& nums){
            int n=nums.size();
            nums.insert(nums.begin(),1);
            nums.push_back(1);
            c_=vector<vector<int>>(n+2,vector<int>(n+2,0));
            return maxCoins(nums,1,n);
        }
    private:
    vector<vector<int>> c_;
    int maxCoins(const vector<int>& nums,const int i,const int j){
        if(i>j) return 0;
        if(c_[i][j]>0) return c_[i][j];
        if(i==j) return nums[i-1]*nums[i]*nums[i+1];
        int ans=0;

        for(int k=i;k<=j;k++){
            ans=max(ans,maxCoins(nums,i,k)+maxCoins(nums,k+1,j)+nums[i-1]*nums[k]*nums[j+1]);
        }
        c_[i][j]=ans;
        return c_[i][j];
    }
};
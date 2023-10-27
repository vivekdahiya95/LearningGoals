/*

can the given array be partitioned into two arrays with equal sum

*/

#include<bits/stdc++.h>
using namespace std;


bool partitionSum(vector<int> & nums){
    const int sum=accumulate (nums.begin(),nums.end(),0);
    if(sum%2) return false;

    vector<int> dp(sum+1,0);
    dp[0]=1;
    for(const int num:nums){
        for(int i=sum;i>=0;i--){
            if(dp[i]){
                dp[i+num]=1;
            }
        }
        if (dp[sum/2]) return true;
    }
    return false;

}
/**
 * subset sum with max difference-> see it wrt the last row of the abbove dp problem
 * number of subsets with a given sum-> instead of or in the suset sum problem use +
 * subset with given difference
 * target Sum-> +/- against each element in the given array-> reduce it to target sum
 */
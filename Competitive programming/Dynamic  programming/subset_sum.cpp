/*
Given an array of integers you have to return if a possbile target sum can be made using the subset of integers
*/

/*
solution notes:

if the current num is less than the number required you can include it in the running Sum and run a lop
and || it without a call that is not including it 
*/

#include<bits/stdc++.h>
using namespace std;

int n=5;
int target=11;

bool dp[5+1][11+1];
/*
dp looks something like this in the initialization itself
{
    {T,F,F,F,F,F,F,F,F,F,F,F},
    {T,F,F,F,F,F,F,F,F,F,F,F},
    {T,F,F,F,F,F,F,F,F,F,F,F},
    {T,F,F,F,F,F,F,F,F,F,F,F},
    {T,F,F,F,F,F,F,F,F,F,F,F},
    {T,F,F,F,F,F,F,F,F,F,F,F}
}
*/


bool subsetSum(int arr[],int n, int target){
    // making the subset sum array
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}
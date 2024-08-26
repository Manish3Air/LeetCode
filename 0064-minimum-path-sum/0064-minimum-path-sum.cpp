#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long mini(int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        long up=grid[m][n]+mini(m-1,n,grid,dp); 
        long left=grid[m][n]+mini(m,n-1,grid,dp); 
        return dp[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return mini(m-1,n-1,grid,dp);
    }
};
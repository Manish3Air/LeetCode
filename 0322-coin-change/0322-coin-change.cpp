class Solution {
public:
  int f(int idx,vector<int> &coins, int sum,vector<vector<int>>& dp){
    
    if(idx == 0){
        if(sum%coins[0] == 0) return sum/coins[0];
        else return  1e9;
    } 
    if(dp[idx][sum] != -1) return dp[idx][sum];
    int not_take = f(idx - 1,coins,sum,dp);
    int take = 1e9;
    if(sum >= coins[idx]){
        take = 1 + f(idx,coins,sum-coins[idx],dp);
    }
    return dp[idx][sum]=min(take,not_take);
  }
    
    int coinChange(vector<int>& coins, int sum) {
        int N = coins.size();
        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        int ans = f(N-1,coins,sum,dp);
        return ans == 1e9 ? -1 : ans;
    }
};
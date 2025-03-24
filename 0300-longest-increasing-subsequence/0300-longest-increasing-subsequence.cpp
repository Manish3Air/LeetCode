class Solution {
public:
int f(int idx,int prev_idx,vector<int>& arr,vector<vector<int>>& dp){
      if(idx >= arr.size()){
        return 0;  
      }
      if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
      int n_take = 0 + f(idx + 1,prev_idx,arr,dp);
      int take = 0;
      if(prev_idx == -1 || arr[idx] > arr[prev_idx]){
           take =  1 + f(idx+1,idx,arr,dp);
      }
      return dp[idx][prev_idx + 1] = max(n_take,take);
  }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n + 1,-1));
        return f(0,-1,arr,dp);
    }
};
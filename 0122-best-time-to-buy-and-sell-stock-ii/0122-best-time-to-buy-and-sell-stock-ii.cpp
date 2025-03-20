class Solution {
public:

long f(int idx,int buy,vector<int>& prices, int n,vector<vector<int>>& dp){
    if(idx == n) return 0;
    if(dp[idx][buy] != -1) return dp[idx][buy];
    int profit = 0;
    if(buy){
        profit = max(-prices[idx] + f(idx + 1,0,prices,n,dp),0 + f(idx + 1,1,prices,n,dp));
    }else{
        profit = max(prices[idx] + f(idx + 1,1,prices,n,dp),0 + f(idx + 1,0,prices,n,dp));
    }
    return dp[idx][buy] = profit;
}

    int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int res = 0;
    //     for (long i = 1; i < n; i++) {
    //     if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
    //     }
        
    // return res;

    int n = prices.size();
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    
    vector<vector<long>> dp(n + 1,vector<long>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int idx = n - 1; idx >=0; idx--){
        for(int buy = 0; buy <= 1; buy++){
        long profit = 0;
    if(buy){
        profit = max(-prices[idx] + dp[idx + 1][0], 0 + dp[idx + 1][1]);
    }else{
        profit = max(prices[idx] + dp[idx + 1][1],0 + dp[idx + 1][0]);
    }
     dp[idx][buy] = profit;
        }
    }
    return dp[0][1];

    //    return f(0,1,prices,n,dp);
      


    }
};
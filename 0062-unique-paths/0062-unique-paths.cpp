class Solution {
public:
    int TS(int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=TS(m-1,n,dp);
        int left=TS(m,n-1,dp);

        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return TS(m-1,n-1,dp);
    }
};
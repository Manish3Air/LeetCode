class Solution {
public:
    int TS(int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid) {
        
        if (obstacleGrid[m][n]) return 0;
        if (m == 0 && n == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];

        int up = 0, left = 0;
        if (m > 0) up = TS(m - 1, n, dp, obstacleGrid);
        if (n > 0) left = TS(m, n - 1, dp, obstacleGrid);

        return dp[m][n] = (up + left);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return TS(m - 1, n - 1, dp, obstacleGrid);
    }
};

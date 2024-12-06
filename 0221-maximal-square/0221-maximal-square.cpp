class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int>> dp(N,vector<int>(M,0));
        for(int j=0;j<M;j++){ 
            dp[0][j] = matrix[0][j] - '0';
        }
        for(int i=1;i<N;i++) {
            dp[i][0] = matrix[i][0] - '0';
            }
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i][j-1],
                    min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi * maxi;
    }
};
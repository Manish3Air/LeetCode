class Solution {
public:
int f(int idx, vector<int>& arr, int N, vector<int>& dp) {
        if (idx >= N - 1) return 0; 
        if (arr[idx] == 0) return 1e9; 

        if (dp[idx] != -1) return dp[idx]; 

        int minJumps = 1e9;
        for (int jump = 1; jump <= arr[idx]; jump++) {
            if (idx + jump < N) {
                minJumps = min(minJumps, 1 + f(idx + jump, arr, N, dp));
            }
        }
        return dp[idx] = minJumps;
    }

    int jump(vector<int>& arr) {
       int N = arr.size();
        vector<int> dp(N, -1);
        int ans = f(0, arr, N, dp);
        return (ans >= 1e9) ? -1 : ans;  
    }
};
class Solution {
public:

    bool f(int idx, vector<int>& arr, int N, vector<int>& dp) {
        if (idx == N - 1) return true; 
        if (dp[idx] != -1) return dp[idx]; 

        
        for (int jump = 1; jump <= arr[idx]; jump++) {
            if (f(idx + jump,arr,N,dp) == true) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, -1);
        return f(0, nums, N, dp);
       
    }
};
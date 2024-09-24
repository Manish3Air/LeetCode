class Solution {
public:
    bool f(int i, long long target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == nums.size() || target < 0) return false;

        if (dp[i][target] != -1) return dp[i][target];

        if (f(i + 1, target, nums, dp)) return dp[i][target] = true;

        if (nums[i] <= target) {
            if (f(i + 1, target - nums[i], nums, dp)) return dp[i][target] = true;
        }

        return dp[i][target] = false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % 2 != 0) return false;

        long long target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(0, target, nums, dp);
    }
};

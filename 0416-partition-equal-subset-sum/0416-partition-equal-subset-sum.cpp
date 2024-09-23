class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        // If the sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // 1D DP array
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        // Process each number in nums
        for (int num : nums) {
            // Traverse backwards to ensure we don't overwrite results prematurely
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // If we can partition the array, there will be a subset with sum equal to target
        return dp[target];
    }
};

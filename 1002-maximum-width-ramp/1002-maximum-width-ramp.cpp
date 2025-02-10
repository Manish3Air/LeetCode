class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> maximum(nums.size(), 0);
        int maxi = INT_MIN;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] >= maxi) {
                maxi = nums[i];
                maximum[i] = maxi;
            }else maximum[i] = maxi;
        }

        int i = 0, j = 0;
        int ans = 0;
        
        while (j < nums.size()) {
            if (nums[i] <= maximum[j]) {
                ans = max(ans, j - i);  
                j++;  
            } else {
                i++;  
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxamount(int index,vector<int>& nums,vector<int>& dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int left=nums[index] + maxamount(index-2,nums,dp);
        int right=maxamount(index-1,nums,dp);
        return dp[index]= max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return maxamount(n-1,nums,dp);
    }
};
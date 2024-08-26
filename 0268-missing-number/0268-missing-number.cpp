class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N=nums.size();
        int sumtillN=(N)*(N+1)/2;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
        }
        int p=sumtillN-sum;
        return p;
    }
};
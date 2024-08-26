class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int N=nums.size();
        // int targ=N/2;
        // int count=1;
        // int ans,i;
        // for( i=0;i<N-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         count++;
        //     }
        //     else{
        //         if(count>targ){
        //              ans=nums[i];
        //              break;
        //         }
        //         else{
        //             count=1;
        //         }
        //     }
        // }
        // if(count>targ){
        //     ans=nums[i];
        // }
        // return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
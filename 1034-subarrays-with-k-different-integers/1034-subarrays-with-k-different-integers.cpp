class Solution {
public:

    int TSALEK(vector<int>& nums, int k){
        int count=0,l=0,r=0;
        unordered_map<int,int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l=l+1;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res1 =  TSALEK(nums,k); 
        int res2 =  TSALEK(nums,k-1);
        return res1 - res2;
    }
};
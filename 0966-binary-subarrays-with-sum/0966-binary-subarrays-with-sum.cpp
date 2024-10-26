class Solution {
public:
 int countsubstrings(vector<int>& s, int k) {
    if(k<0) return 0;
        int N = s.size();
         int count = 0;
        int l = 0, r = 0;
        int sum = 0;
        while (r < N) {
            sum+=s[r];
            while(sum > k) {
                sum-=s[l];
                l++;
            }
            if (sum <= k) {
                count += r - l + 1;
            }
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return countsubstrings(nums,k) - countsubstrings(nums,k-1);
    }
};
class Solution {
public:
     int countsubstrings(vector<int>& s, int k) {
        int N = s.size();
         int count = 0;
        int l = 0, r = 0;
        int sum = 0;
        while (r < N) {
            sum+=s[r]%2;
            while (sum > k) {
                sum-=s[l]%2;
                l++;
            }
            if (sum <= k) {
                count += r - l + 1;
            }
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countsubstrings(nums,k) - countsubstrings(nums,k-1);
    }
};
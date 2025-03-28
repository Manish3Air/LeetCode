class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left=(m+n)-1;
    int right=n-1;
    while(right>=0){
        swap(nums1[left],nums2[right]);
        left--;
        right--;
    }
    sort(nums1.begin(),nums1.end());
    
    }
};
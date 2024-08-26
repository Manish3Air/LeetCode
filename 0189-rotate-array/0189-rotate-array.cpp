#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n=nums.size();
        int d=k%n;
         vector<int> arr;
        for(int i=n-d;i<n;i++){
            arr.push_back(nums[i]);
        }
        for(int i=n-d-1;i>=0;i--){
            nums[i+d]=nums[i];
        }
        for(int i=0;i<d;i++){
            nums[i]=arr[i];
        }

    }
};
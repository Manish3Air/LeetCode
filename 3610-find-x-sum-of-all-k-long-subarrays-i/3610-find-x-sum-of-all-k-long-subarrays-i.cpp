#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   static bool comp(pair<int,int>& p1,pair<int,int>& p2){
            if(p2.second < p1.second) return true;
            if(p2.second > p1.second) return false;

            if(p1.first > p2.first) return true;
            else return false;
        }
    int sorter(unordered_map<int, int>& M,int x) { 
    vector<pair<int, int> > A; 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
    sort(A.begin(), A.end(), comp); 
        int sum = 0;
        int count = 0;
        for(auto it:A){
            if(++count > x) break;
            sum = sum + (it.second * it.first);
        }
        return sum;
} 
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int totsum = accumulate(nums.begin(),nums.end(),0);
        vector<int> ans(n-k+1,totsum);
        for(int j=0;j<n-k+1;j++){
         unordered_map<int,int> mp;
        for(int i=j;i<k+j;i++){
            mp[nums[i]]++;
        }
        if(mp.size()<x && k==n) {
            continue;
        }
        int sum = sorter(mp,x);
        ans[j] =sum;
        }
       return ans;
    }
};
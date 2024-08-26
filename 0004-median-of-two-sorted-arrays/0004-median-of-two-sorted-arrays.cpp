#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {        int m=nums1.size();
         int n= nums2.size();
         vector<int> merge;
        for(int i=0;i<m;i++){
            merge.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            merge.push_back(nums2[i]);
        }
        int P=merge.size();
        sort(merge.begin(),merge.end());
        if(P%2==0){
            int R=P/2;
             return (double) (merge[R-1]+merge[R])/2;
        }
        else{
            int Q=(P+1)/2;
            return (double) merge[Q-1];
        }
        
    }
};
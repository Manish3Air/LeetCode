#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 
void tPC(int idx,int t,vector<int> &arr,vector<int> &P,vector<vector<int>> &ans){
  if (t == 0) {
    ans.push_back(P);
    return;
  }
    for(int i=idx;i<arr.size();i++){
        if(arr[i]>t) break;
      if (i>idx && arr[i] == arr[i-1]) continue;
        P.push_back(arr[i]);
        tPC(i + 1, t - arr[i], arr, P, ans);
        P.pop_back();
      
    }
}

vector<vector<int>> combinationSum2(vector<int> &ARR, int target){
	// Write your code here.
	sort(ARR.begin(),ARR.end());
    vector<vector<int>> ans;
    vector<int> P;
    tPC(0,target,ARR,P,ans);
    return ans;
}

};

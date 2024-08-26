#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void tPC(int idx,int t,vector<int> &P,vector<vector<int>> &ans,int k){
  if (P.size()==k) {
    if (t == 0) {
      ans.push_back(P);
    }
    return;
  }
    for(int i=idx;i<=9;i++){
        if(i>t) break;
        P.push_back(i);
        tPC(i + 1, t -i, P, ans,k);
        P.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
     vector<vector<int>> ans;
    vector<int> P;
    tPC(1,n,P,ans,k);
    return ans;
}  
};
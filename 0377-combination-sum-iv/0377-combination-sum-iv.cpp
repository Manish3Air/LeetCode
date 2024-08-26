#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
int tpc(vector<int> &num, int tar,int currsum, vector<int> &dp){
   if(dp[currsum]!=-1) return dp[currsum];
    if(currsum==tar) return 1;
    if(currsum > tar) return 0;
    int ans=0;
    for(int i=0;i<num.size();i++){
        if(currsum<tar){
            currsum+=num[i];
            ans+=tpc(num,tar,currsum,dp);
            currsum-=num[i];
        }
    }
    return dp[currsum] = ans;
}
    int combinationSum4(vector<int>& num, int tar) {
        int max=*max_element(num.begin(),num.end());
    vector<int> dp(tar+max,-1);
    return tpc(num,tar,0,dp);
    }
};
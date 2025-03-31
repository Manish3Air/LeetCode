class Solution {
public:
static bool comp(string &s1,string &s2){
      return s1.length() < s2.length();
  }
  bool compare(string &s1,string &s2){
      if(s1.size() != s2.size() + 1) return false;
      int first = 0;
      int second = 0;
      while(first < s1.size()){
          if(s1[first] == s2[second]){
              first++;
              second++;
          }else{
              first++;
          }
      }
      if(first == s1.size() && second == s2.size()) return true;
      return false;
  }
  int f(int idx,int prev_idx,vector<string>& arr,vector<vector<int>>& dp){
      if(idx >= arr.size()){
        return 0;  
      }
      if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
      int n_take = 0 + f(idx + 1,prev_idx,arr,dp);
      int take = 0;
      if(prev_idx == -1 || compare(arr[idx],arr[prev_idx])){
           take =  1 + f(idx+1,idx,arr,dp);
      }
      return dp[idx][prev_idx + 1] = max(n_take,take);
  }
   
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n,vector<int>(n + 1,-1));
        sort(words.begin(),words.end(),comp);
        return f(0,-1,words,dp);
    }
};
class Solution {
public:
    bool solve(int idx,string &s,unordered_set<string> &s1,vector<int> &dp){
        if(idx >= s.size()){
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        if(s1.find(s.substr(idx,s.size())) != s1.end()) return true;
        for(int len = 1; len <= s.size(); len++){
            string temp = s.substr(idx,len);
            if(s1.find(temp) != s1.end() && solve(idx + len,s,s1,dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> s1(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(0,s,s1,dp);
    }
};
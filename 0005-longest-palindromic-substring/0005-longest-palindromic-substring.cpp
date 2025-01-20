class Solution {
public:
    bool check(string& s,int i,int j,vector<vector<int>>& dp){
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = check(s,i+1,j-1,dp);
        
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();
        if(n == 0) return res;

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(s,i,j,dp)){
                    int len = j-i+1;
                    if(len > maxi){
                        res = s.substr(i,len);
                        maxi = len;
                    }
                }
            }
        }
        return res;
    }
};
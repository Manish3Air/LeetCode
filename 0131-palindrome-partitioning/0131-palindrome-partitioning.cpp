class Solution {
public:
bool check(string temp,int i,int j){
    while( i < j){
        if(temp[i] != temp[j]) return false;
        i++,j--;
    }
    return true;
}

void solve(int idx, vector<vector<string>> &ans, vector<string> &curr, string &s){
            if(idx == s.size()){
                ans.push_back(curr);
                return;
            }
            for(int i = idx; i < s.size(); i++){
                if(check(s,idx,i)){
                    curr.push_back(s.substr(idx,i-idx+1));
                    solve(i+1,ans,curr,s);
                    curr.pop_back();
                }
            }

}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,ans,curr,s);
        return ans;
    }
};
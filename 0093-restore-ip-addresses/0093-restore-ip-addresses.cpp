class Solution {
public:
    bool isValid(string temp){
        if(temp.size() > 1 && temp[0] == '0') return false;
        int num = stoi(temp);
        return num<=255;
    }
    void solve(int idx, int parts, vector<string> &ans, string str,int n, string &s){
        if(idx == n && parts == 4){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        
        if(idx >=n || parts >= 4) return;
        
        solve(idx + 1,parts + 1,ans,str + s.substr(idx,1) + '.' ,n,s);
        
        if(idx + 2 <= n && isValid(s.substr(idx,2))){
            solve(idx + 2,parts + 1,ans,str +  s.substr(idx,2) + '.' ,n,s);

        }
        if(idx + 3 <= n && isValid(s.substr(idx,3))){
            solve(idx + 3,parts + 1,ans,str + s.substr(idx,3) + '.' ,n,s);

        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if(n > 12) return {};
        vector<string> ans;
        string str;
        solve(0,0,ans,str,n,s);
        return ans;
    }
};
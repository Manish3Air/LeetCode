class Solution {
public:
    void LCP(string digits,int index,string s,vector<string> &ans,string mapping[]){
        if(index>=digits.size()){
            ans.push_back(s);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0;i<value.size();i++){
            s.push_back(value[i]);
            LCP(digits,index+1,s,ans,mapping);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s="";
        if(digits.size()==0) return ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        LCP(digits,0,s,ans,mapping);
        return ans;
    }
};
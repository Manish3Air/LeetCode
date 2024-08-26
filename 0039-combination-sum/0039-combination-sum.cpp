class Solution {
public:

    void func(int index,vector<int>& candidates, int target,vector<int>&p,set<vector<int>>& ans){
        if(index==candidates.size()){
            if(target==0){
                ans.insert(p);
            }
            return;
        }
        if(candidates[index]<=target){
        p.push_back(candidates[index]);
        
        func(index,candidates,target-candidates[index],p,ans);
        
        p.pop_back();
        }
       func(index+1,candidates,target,p,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        set<vector<int>> s1;
        vector<int> p;
            func(0,candidates,target,p,s1);
            vector<vector<int>> ans(s1.begin(),s1.end());
            return ans;
    }
};
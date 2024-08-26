class Solution {
public:
void subsequence(vector<int>&v,vector<vector<int>>& ans,int i,vector<int>& p){

    if(i==v.size()){

        ans.push_back(p);

        return;

    }

    p.push_back(v[i]);

    subsequence(v,ans,i+1,p);

    p.pop_back();

    subsequence(v,ans,i+1,p);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> p;
        subsequence(nums,ans,0,p);
        return ans;
    }
};
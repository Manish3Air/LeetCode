class Solution {
public:
void TPC(int index,vector<int> &arr,vector<int> &P,set<vector<int>> &ans){
      if(index==arr.size()){
          ans.insert(P);
          return;
      }
      P.push_back(arr[index]);
      TPC(index+1,arr,P,ans);
      P.pop_back();
       TPC(index+1,arr,P,ans);
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>> s1;
        vector<int> P;
        sort(nums.begin(),nums.end());
        TPC(0,nums,P,s1);
        vector<vector<int>> ans(s1.begin(),s1.end());
        return ans;
    }
};
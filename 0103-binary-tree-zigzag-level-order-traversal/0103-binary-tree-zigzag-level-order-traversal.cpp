
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<int,TreeNode*>> q1;
        map<int,vector<int>> mp;
        q1.push({0,root});
        while(!q1.empty()){
            pair<int,TreeNode*> p1 = q1.front();
            q1.pop();
            TreeNode* temp = p1.second;
            int lvl = p1.first;
            int data = temp->val;
            mp[lvl].push_back(data);
             if(temp->left){
                q1.push({lvl+1,temp->left});
            }
            if(temp->right){
                q1.push({lvl+1,temp->right});
            }
           
        }
        vector<vector<int>> ans;
        for(auto &[x,y] : mp){
            if(x & 1){
                reverse(y.begin(),y.end());
                ans.push_back(y);
                
            }else{
                ans.push_back(y);
            }
        }
        return ans;
    }
};
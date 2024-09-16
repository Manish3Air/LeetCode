#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxpath(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int leftsum= max(0,maxpath(root->left,maxi));
        int rightsum=max(0,maxpath(root->right,maxi));
        maxi=max(maxi,(leftsum+rightsum+root->val));
        return max(rightsum,leftsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
};
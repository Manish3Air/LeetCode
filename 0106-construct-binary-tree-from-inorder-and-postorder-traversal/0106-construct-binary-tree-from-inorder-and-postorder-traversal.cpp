
class Solution {
public:
    TreeNode* build(vector<int>& inorder,int inStart,int inEnd, vector<int>& postorder,int postStart,int postEnd,unordered_map<int,int> &mp){
        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = mp[postorder[postEnd]];
        int numsLeft =  idx - inStart;
        root->left = build(inorder,inStart,idx - 1,
                    postorder,postStart, postStart + numsLeft - 1,mp);
        root->right = build(inorder,idx + 1,inEnd,
                        postorder,postStart + numsLeft,postEnd - 1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return build(inorder,0,inorder.size() - 1,
                postorder,0,postorder.size() - 1,mp);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        Pre(root,ans);
        return ans;
        
    }
    void Pre(TreeNode* root, vector<int>& ans){
        
        if(!root)
            return;
        
        ans.push_back(root->val);
        Pre(root->left, ans);
        Pre(root->right, ans);
        
    }
};

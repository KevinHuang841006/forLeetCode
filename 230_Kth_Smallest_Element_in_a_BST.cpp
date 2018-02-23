/**
 *
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 
 *Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        vector <int> ans;
        tree(root, ans);
        
        
        
        return ans[k-1];
    }
    
    void tree(TreeNode* root, vector<int>& ans){
        
        if(!root)
            return;
        tree(root->left, ans);
        ans.push_back(root->val);
        tree(root->right, ans);
    }
    
    
};

/**
有多種解法，但要注意：若要用buttom up ，要記得清除Link

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6



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
    
    void flatten(TreeNode* root) {
        
        if(!root)
            return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        //！！！！！！  一定要記得清除Link 
        root->left = NULL;
        root->right = NULL;
        
        flatten(left);
        flatten(right);
        
        root->right = left;
        TreeNode* temp = root;
        while(temp->right)
            temp=temp->right;
        temp->right =right;
    }
    
    
    
};

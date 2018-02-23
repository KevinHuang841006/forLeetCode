/**

重點：要會遞迴紀錄樓層數 floor
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



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
    int max=0;
    int flag[900000]={0};
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        
        if(!root)
            return ans;
        
        int floor=-1;
        find(root,floor,ans);
        return ans;
    }
    void find(TreeNode* root, int floor, vector<int>& ans){
        if(!root)
            return;
        floor++;
        if(max<floor)
            max=floor;
        if(flag[floor]==0){
            ans.push_back(root->val);
            flag[floor]++;
        }
        
        find(root->right,floor,ans);
        find(root->left,floor,ans);
        
        floor--;
    }
    
};

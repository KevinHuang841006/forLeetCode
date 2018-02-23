/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        
        //為NULL leaf的子點
        
        if(!head)
            return NULL;
        //一定要加！！！！！  為Leaf
        if(!head->next){
            
            return new TreeNode(head->val);
        }
        
        //不為Leaf
        
        ListNode* mid = findMid(head);
        
        
        TreeNode* root=new TreeNode(mid->val);
        //root->val = mid->val;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
        
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head;
        //slow=head;
        //fast=head;
        ListNode* pre;
        
        /*
            1,2,  3   ,4,5 ,(null)
            s
            f
            
              s
                  f
                  
                  s
                         f
        */
        
        while(fast && fast->next){ //小心fast ==NULL也要考慮進去
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=NULL;
        return slow;
        
    }
    
    
};
